/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_preparation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:11:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 23:47:05 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push_marked_nodes(t_stacks *stks)
{
	t_stack		*stk_a;
	t_stack		*stk_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	while (stk_has_marked_node(stk_a->list))
		push_closest_marked_node(stks);
}

static void	mark_nodes_to_be_pushed(t_node *start_node, t_node *stk_top)
{
	int		curr_max_val;
	t_node	*node;

	curr_max_val = start_node->val;
	start_node->is_sorted = true;
	// printf("val: %ld, is_sorted: %d\n", start_node->val, start_node->is_sorted);
	node = start_node->next;
	if (node == NULL)
		node = stk_top;
	while (node != start_node)
	{
		if (node->val > curr_max_val)
		{
			curr_max_val = node->val;
			node->is_sorted = true;
		}
		// printf("val: %ld, is_sorted: %d\n", node->val, node->is_sorted);
		node = node->next;
		if (node == NULL)
			node = stk_top;
	}
}

static t_node	*find_longest_coherent_list(t_node *stk)
{
	t_node			*ptr;
	t_node			*max_node;
	unsigned int	curr_ordered_el_count;
	unsigned int	max_ordered_el_count;

	ptr = stk;
	max_node = stk;
	max_ordered_el_count = get_ordered_el_count(ptr, stk);
	while (ptr)
	{
		curr_ordered_el_count = get_ordered_el_count(ptr, stk);
		// printf("curr_ord_el_c: %u\n", curr_ordered_el_count);
		// if (curr_ordered_el_count > max_ordered_el_count)
		if (curr_ordered_el_count > max_ordered_el_count
			|| (curr_ordered_el_count == max_ordered_el_count
			&& ptr->index < max_node->index))
		{
			max_node = ptr;
			max_ordered_el_count = curr_ordered_el_count;
		}
		ptr = ptr->next;
	}
	return (max_node);
}

void	prepare_stacks_for_sorting(t_stacks *stks)
{
	t_node	*stk_a;
	t_node	*optimal_node;

	stk_a = stks->a.list;
	add_indexing(stks);
	optimal_node = find_longest_coherent_list(stk_a);
	mark_nodes_to_be_pushed(optimal_node, stk_a);
	push_marked_nodes(stks);
}
