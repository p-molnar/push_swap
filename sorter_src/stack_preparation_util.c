/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_preparation_util.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 23:02:51 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:19:18 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

size_t	get_false_node_position(t_node *stk, int lookup)
{
	size_t	counter;
	size_t	first;
	size_t	last;

	counter = 0;
	first = 0;
	last = 0;
	while (stk)
	{
		if (stk->is_in_order == false)
		{
			if (lookup == 1)
				return (counter);
			last = counter;
		}
		counter++;
		stk = stk->next;
	}
	if (lookup == -1)
		return (last);
	return (last);
}

// original
void	push_closest_marked_node(t_stacks *stks)
{
	t_stack			*stk_a;
	t_stack			*stk_b;
	unsigned int	first_false_position;
	unsigned int	last_false_position;

	stk_a = &stks->a;
	stk_b = &stks->b;
	first_false_position = get_false_node_position(stk_a->list, 1);
	last_false_position = get_false_node_position(stk_a->list, -1);
	if (first_false_position < (stk_a->size - last_false_position))
	{
		while (stk_a->list->is_in_order != false)
			rotate(&stk_a, false, true);
	}
	else
	{
		while (stk_a->list->is_in_order != false)
			rotate(&stk_a, true, true);
	}
	push(&stk_a, &stk_b, true);
}

bool	stk_has_marked_node(t_node *stk)
{
	t_node	*ptr;

	ptr = stk;
	while (ptr)
	{
		if (ptr->is_in_order == false)
			return (true);
		ptr = ptr->next;
	}
	return (false);
}

size_t	get_ordered_node_count(t_node *node, t_node *stk_top)
{
	const t_node	*start_node;
	unsigned int	ordered_el_count;
	int				curr_max_val;
	t_node			*tmp_ptr;

	start_node = node;
	ordered_el_count = 0;
	curr_max_val = node->val;
	tmp_ptr = node->next;
	if (tmp_ptr == NULL)
		tmp_ptr = stk_top;
	while (tmp_ptr->val != start_node->val)
	{
		if (tmp_ptr->val > curr_max_val)
		{
			curr_max_val = tmp_ptr->val;
			ordered_el_count++;
		}
		tmp_ptr = tmp_ptr->next;
		if (tmp_ptr == NULL)
			tmp_ptr = stk_top;
	}
	return (ordered_el_count);
}
