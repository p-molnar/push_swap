/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_preparation_util.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 23:02:51 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/18 15:45:53 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

unsigned int	get_false_node_position(t_node *stk, int lookup)
{
	unsigned int	counter;
	unsigned int	first;
	unsigned int	last;

	counter = 0;
	first = 0;
	last = 0;
	while (stk)
	{
		if (stk->is_sorted == false)
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
		while (stk_a->list->is_sorted != false)
			rotate(&stk_a, false, true);
	}
	else
	{
		while (stk_a->list->is_sorted != false)
			rotate(&stk_a, true, true);
	}
	push(&stk_a, &stk_b, true);
}

bool	stk_has_marked_node(t_node *stk)
{
	while (stk)
	{
		if (stk->is_sorted == false)
			return (true);
		stk = stk->next;
	}
	return (false);
}

unsigned int	get_ordered_el_count(t_node *node, t_node *stk_top)
{
	const t_node	*start_node;
	unsigned int	ordered_el_count;
	int				curr_max_val;

	start_node = node;
	ordered_el_count = 0;
	curr_max_val = node->val;
	node = node->next;
	if (node == NULL)
		node = stk_top;
	while (node != start_node)
	{
		if (node->val > curr_max_val)
		{
			curr_max_val = node->val;
			ordered_el_count++;
		}
		node = node->next;
		if (node == NULL)
			node = stk_top;
	}
	return (ordered_el_count);
}
