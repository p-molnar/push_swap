/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_preparation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 12:56:14 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/03 21:54:11 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	mark_out_of_order_nodes(t_node *start_node, t_node *stk_top)
{
	int		curr_max_val;
	t_node	*tmp;

	curr_max_val = start_node->val;
	start_node->is_in_order = true;
	tmp = start_node->next;
	if (tmp == NULL)
		tmp = stk_top;
	while (tmp != start_node)
	{
		if (tmp->val > curr_max_val)
		{
			curr_max_val = tmp->val;
			tmp->is_in_order = true;
		}
		else
			tmp->is_in_order = false;
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = stk_top;
	}
}

static t_node	*get_longest_ordered_list_head(t_node *stk)
{
	t_node	*tmp;
	t_node	*max_node;
	size_t	curr_ordered_el_count;
	size_t	max_ordered_el_count;

	tmp = stk;
	max_node = stk;
	max_ordered_el_count = get_ordered_node_count(tmp, stk);
	while (tmp)
	{
		curr_ordered_el_count = get_ordered_node_count(tmp, stk);
		if (curr_ordered_el_count >= max_ordered_el_count \
			|| tmp->index < max_node->index)
		{
			max_node = tmp;
			max_ordered_el_count = curr_ordered_el_count;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

static bool	is_swap_beneficial(t_stack *stk)
{
	t_node	*ordered_list_head;
	size_t	ordered_node_count;

	ordered_list_head = get_longest_ordered_list_head(stk->list);
	ordered_node_count = get_ordered_node_count(ordered_list_head, stk->list);
	swap(&stk, SILENT);
	ordered_list_head = get_longest_ordered_list_head(stk->list);
	if (get_ordered_node_count(ordered_list_head, \
								stk->list) > ordered_node_count)
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
	ordered_list_head = get_longest_ordered_list_head(stk_a->list);
	index_list(stks);
	mark_out_of_order_nodes(ordered_list_head, stk_a->list);
	while (stk_has_marked_node(stk_a->list) == true)
	{
		if (is_swap_beneficial(&stks->a) == true)
		{
			swap(&stk_a, VERBOSE);
			index_list(stks);
			ordered_list_head = get_longest_ordered_list_head(stk_a->list);
			mark_out_of_order_nodes(ordered_list_head, stk_a->list);
		}
		else if (stk_a->list->is_in_order == false)
			push(&stk_a, &stk_b, VERBOSE);
		else
			rotate(&stk_a, NO_REVERSE, VERBOSE);
	}
}
