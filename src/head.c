/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   head.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 14:11:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 01:30:29 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_custom_data_types.h>

unsigned int get_false_node_position(t_node *stk, int lookup)
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
				return counter;
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
			rotate(&stk_a, false);
	}
	else
	{
		while (stk_a->list->is_sorted != false)
			rotate(&stk_a, true);
	}
	// print_stacks(stks);
	push(&stk_a, &stk_b);
	// print_stacks(stks);
}

bool	stk_has_marked_node(t_node *stk)
{
	while (stk)
	{
		if (stk->is_sorted == false)
			return true;
		stk = stk->next;
	}
	return (false);
}

void	separate_marked_nodes(t_stacks *stks)
{
	t_stack		*stk_a;
	t_stack		*stk_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	while (stk_has_marked_node(stk_a->list))
		push_closest_marked_node(stks);
}

void	prepare_stacks_for_retain_sorting(t_stacks *stks)
{
	t_node	*stk_a;
	t_node	*optimal_node;

	stk_a = stks->a.list;
	add_indexing(stk_a);

	optimal_node = find_longest_coherent_list(stk_a);
	mark_nodes_to_be_pushed(optimal_node, stk_a);
	separate_marked_nodes(stks);
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

t_node	*find_longest_coherent_list(t_node *stk)
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
		if (curr_ordered_el_count > max_ordered_el_count || 
			(curr_ordered_el_count == max_ordered_el_count && 
			ptr->index < max_node->index))
		{
			max_node = ptr;
			max_ordered_el_count = curr_ordered_el_count;
		}
		ptr = ptr->next;
	}
	return (max_node);
}

void	mark_nodes_to_be_pushed(t_node *start_node, t_node *stk_top)
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
