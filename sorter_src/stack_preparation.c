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

static void	push_marked_nodes(t_stacks *stks)
{
	t_stack		*stk_a;
	t_stack		*stk_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	while (stk_has_marked_node(stk_a->list))
		push_closest_marked_node(stks);
}

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

// void	func(t_stacks *stks, unsigned int prev_max)
// {
// 	t_stacks	*stks_dupl;
// 	t_stack		*stk_a;
// 	unsigned int	i;
// 	t_node			*ordered_list_head;

// 	i = 0;
// 	stks_dupl = duplicate_stks(&stks->a, &stks->b);
// 	stk_a = &stks_dupl->a;
// 	ordered_list_head = find_longest_ordered_list_head(stk_a->list);
// 	unsigned int	ord_el_c = get_ordered_el_count(ordered_list_head, stk_a->list);
// 	while (i++ < stk_a->size)
// 	{
// 		// printf("ord_el_c: %d\n", ord_el_c);
// 		swap(&stk_a, false);
// 		ordered_list_head = find_longest_ordered_list_head(stk_a->list);
// 		if (get_ordered_el_count(ordered_list_head, stk_a->list) < ord_el_c)
// 			swap(&stk_a, false);
// 		ordered_list_head = find_longest_ordered_list_head(stk_a->list);
// 		ord_el_c = get_ordered_el_count(ordered_list_head, stk_a->list);
// 		rotate(&stk_a, false, false);
// 	}
// 	free_nodes(stks_dupl);
// 	// func(stks, max);
// }


bool	is_swap_beneficial(t_stack *stk)
{
	t_node *ordered_list_head;

	ordered_list_head = find_longest_ordered_list_head(stk->list);
	unsigned int ord_el_count = get_ordered_el_count(ordered_list_head, stk->list);
	swap(&stk, false);
	stk->total_op_count -= 1;
	ordered_list_head = find_longest_ordered_list_head(stk->list);
	if (get_ordered_el_count(ordered_list_head, stk->list) > ord_el_count)
	{
		swap(&stk, false);
		stk->total_op_count -= 1;
		return (true);
	}
	else
	{
		swap(&stk, false);
		stk->total_op_count -= 1;
		return (false);
	}
}
void	rotate_toward_min_op(t_stack *stk)
{
	unsigned int	first_false_position;
	unsigned int	last_false_position;

	first_false_position = get_false_node_position(stk->list, 1);
	last_false_position = get_false_node_position(stk->list, -1);
	if (first_false_position < (stk->size - last_false_position))
	{
		rotate(&stk, false, true);
	}
	else
	{
		rotate(&stk, true, true);
	}
}

void	func(t_stacks *stks, unsigned prev_max)
{
	t_stacks	*stks_dup;
	t_stack		*stk_a;
	unsigned int	i;
	unsigned int	j;
	int				i_max = -1;

	// printf("---passed in ---\n");
	// print_stacks(stks);
	// printf("----------------\n");
	i = 0;
	while (i < stks->a.size)
	{
		stks_dup = duplicate_stks(&stks->a, &stks->b);
		// print_stacks(stks_dup);
		stk_a = &stks_dup->a;
		j = 0;
		if (i < stk_a->size / 2)
		{
			while (j++ < i)
				rotate(&stk_a, false, false);
		}
		else
		{
			while (j++ < stk_a->size - i)
				rotate(&stk_a, true, false);
		}
		swap(&stk_a, false);
		unsigned int curr_ord_el_c = get_ordered_el_count(find_longest_ordered_list_head(stk_a->list), stk_a->list);
		// printf("move_c_a: %d, move_c_b: %d\n", stks_dup->a.total_op_count, stks_dup->b.total_op_count);
		// printf("curr_ord_el_c: %d, prev_ord_el_c: %d\n", get_ordered_el_count(find_longest_ordered_list_head(stk_a->list), stk_a->list), prev_max);
		// print_stacks(stks_dup);
		if (curr_ord_el_c > prev_max)
		{
			i_max = i;
			prev_max = curr_ord_el_c;
			// printf("i_max: %d\n", i_max);
			// printf("---optimal stk---\n");
			// print_stacks(stks);
			// printf("----------------\n");
		}
		free(stks_dup);
		i++;
	}
	// do the stuff on the original stack as well.
	j = 0;
	stk_a = &stks->a;
	// printf("size: %d\n", stk_a->size);
	// printf("i_max > size / 2: %d\n", i_max < (stk_a->size / 2));
	if (i_max < (int) (stk_a->size / 2))
	{
		while ((int) j++ < i_max)
			rotate(&stk_a, false, true);
	}
	else
	{
		while ((int) j++ < (int) stk_a->size - i_max)
			rotate(&stk_a, true, true);
	}
	if (i_max != -1)
	{
		// printf("modifies_based_on_i_max: %d\n", i_max);
		swap(&stk_a, true);
		// printf("--- modified stk ---\n");
		// print_stacks(stks);
		// printf("----------------\n");
		func(stks, prev_max);
	}
}

void	prepare_stacks_for_sorting(t_stacks *stks)
{
	t_node	*stk_a;
	t_node	*ordered_list_head;
	t_stack *stk_a2;
	t_stack *stk_b2;

	stk_a = stks->a.list;
	stk_a2 = &stks->a;
	stk_b2 = &stks->b;
	add_indexing(stks);
	ordered_list_head = find_longest_ordered_list_head(stk_a2->list);
	func(stks, get_ordered_el_count(ordered_list_head, stk_a));
	// exit(0);
	ordered_list_head = find_longest_ordered_list_head(stk_a2->list);
	mark_unordered_nodes(ordered_list_head, stk_a2->list);
	// print_stacks(stks);
	// while (stk_has_marked_node(stk_a2->list))
	// {
	// 	if (is_swap_beneficial(stk_a2) == true)
	// 	{
	// 		swap(&stk_a2, true);
	// 		ordered_list_head = find_longest_ordered_list_head(stk_a2->list);
	// 		mark_unordered_nodes(ordered_list_head, stk_a2->list);
	// 	}
	// 	else if (stk_a2->list->is_sorted == false)
	// 		push(&stk_a2, &stk_b2, true);
	// 	else
	// 	{
	// 		// push_closest_marked_node(stks);
	// 		// rotate_toward_min_op(stk_a2);
	// 		rotate(&stk_a2, false, true);
	// 	}
	// 	// print_stacks(stks);
	// }
	push_marked_nodes(stks);
	// print_stacks(stks);
}
