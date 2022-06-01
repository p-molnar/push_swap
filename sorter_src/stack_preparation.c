/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_preparation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:11:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/20 15:19:23pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// static void	push_marked_nodes(t_stacks *stks)
// {
// 	t_stack		*stk_a;
// 	t_stack		*stk_b;

// 	stk_a = &stks->a;
// 	stk_b = &stks->b;
// 	while (stk_has_marked_node(stk_a->list))
// 		push_closest_marked_node(stks);
// }

static void	mark_unordered_nodes(t_node *start_node, t_node *stk_top)
{
	int		curr_max_val;
	t_node	*node;

	curr_max_val = start_node->val;
	start_node->is_sorted = true;
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
		else
			node->is_sorted = false;
		node = node->next;
		if (node == NULL)
			node = stk_top;
	}
}

static t_node	*find_longest_ordered_list_head(t_node *stk)
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

bool	is_swap_beneficial(t_stack *stk)
{
	t_node 	*ordered_list_head;
	size_t	ordered_node_count;

	ordered_list_head = find_longest_ordered_list_head(stk->list);
	ordered_node_count = get_ordered_el_count(ordered_list_head, stk->list);
	swap(&stk, SILENT);
	ordered_list_head = find_longest_ordered_list_head(stk->list);
	if (get_ordered_el_count(ordered_list_head, stk->list) > ordered_node_count)
	{
		swap(&stk, SILENT);
		return (true);
	}
	else
	{
		swap(&stk, SILENT);
		return (false);
	}
}

void	separate_stacks(t_stacks *stks)
{
	t_node	*ordered_list_head;
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	ordered_list_head = find_longest_ordered_list_head(stk_a->list);
	index_list(stks);
	mark_unordered_nodes(ordered_list_head, stk_a->list);
	while (stk_has_marked_node(stk_a->list) == true)
	{
		if (is_swap_beneficial(&stks->a) == true)
		{
			swap(&stk_a, VERBOSE);
			index_list(stks);
			ordered_list_head = find_longest_ordered_list_head(stk_a->list);
			mark_unordered_nodes(ordered_list_head, stk_a->list);
		}
		else if (stk_a->list->is_sorted == false)
			push(&stk_a, &stk_b, VERBOSE);
		else
			rotate(&stk_a, NO_REVERSE, VERBOSE);
		// print_stacks(stks);
	}
}
