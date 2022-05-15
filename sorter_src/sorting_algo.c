/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/14 20:58:37 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

t_node	*get_matching_node(t_stack *stk, t_node *node)
{
	t_node	*stk_a;

	stk_a = stk->list;
	while (stk_a)
	{
		if (stk_a->val < stk_a->next->val &&
			(node->val > stk_a->val && node->val < stk_a->next->val))
		{
			return (stk_a->next);
		}
		else if (stk_a->val > stk_a->next->val &&
			((node->val > stk_a->val && node->val > stk_a->next->val) ||
			(node->val < stk_a->val && node->val < stk_a->next->val)))
		{
			return (stk_a->next);
		}
		if (stk_a->next->next != NULL)
			stk_a = stk_a->next;
		else
			break ;
	}
	return (stk->list);
}

t_node *get_min_op_count_node(t_stack *stk_a, t_stack *stk_b)
{
	t_node			*node_b;
	t_node			*min_node;
	unsigned int	min_move_count_a;
	unsigned int	min_move_count_b;
	unsigned int	curr_min_move_a;
	unsigned int	curr_min_move_b;

	node_b = stk_b->list;
	min_node = stk_b->list;
	min_move_count_b = -1;
	min_move_count_a = -1;
	while (node_b)
	{
		curr_min_move_b = get_min_move_count(node_b, stk_b) + 1;
		curr_min_move_a = get_min_move_count(get_matching_node(stk_a, node_b), stk_a);
		if (curr_min_move_a + curr_min_move_b < min_move_count_a + min_move_count_b)
		{
			min_move_count_a = curr_min_move_a;
			min_move_count_b = curr_min_move_b;
			// printf("min_move_a: %u\n", min_move_count_a);
			// printf("min_move_b: %u\n", min_move_count_b);
			min_node = node_b;
		}
		node_b = node_b->next;
	}
	return (min_node);
}

void	retain_sort(t_stacks *stks, int stk_size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_node	*node;

	stk_a = &stks->a;
	stk_b = &stks->b;
	while (is_stack_sorted(stk_a->list, stk_size, ASCENDING) != true)
	{
		prepare_stacks_for_sorting(stks);
		// print_stacks(stks);
		while (stk_b->list != NULL)
		{
			node = get_min_op_count_node(stk_a, stk_b);
			// if (node)
			// 	printf("min_node: %ld\n", node->val);
			move_node_to_top(&stk_b, node);
			move_node_to_top(&stk_a, get_matching_node(stk_a, node));
			push(&stk_b, &stk_a);
			// print_stacks(stks);
		}
		move_node_to_top(&stk_a, get_extreme_val(stk_a->list, MIN));
	}
}

void	sort_stack_of_size_3(t_stack **stk, size_t stk_size, int order)
{
	t_node	*top;
	t_node	*mid;
	t_node	*btm;

	top = (*stk)->list;
	mid = top->next;
	if (mid == NULL)
		mid = top;
	btm = mid->next;
	if (btm == NULL)
		btm = mid;
	while (!is_stack_sorted((*stk)->list, stk_size, order))
	{
		if (order * top->val > order * mid->val)
		{
			if (order * top->val > order * btm->val)
				rotate(stk, false);
			else if (order * top->val < order * btm->val)
				swap(stk);
		}
		else if (order * top->val < order * mid->val)
			rotate(stk, true);
		sort_stack_of_size_3(stk, stk_size, order);
	}
}

// void	brute_force(t_stacks *stks, int stk_size)
// {
// 	t_stack	*stk_a;
// 	t_stack	*stk_b;

// 	stk_a = &stks->a;
// 	stk_b = &stks->b;
// 	if (stks != NULL || stk_b->list != NULL)
// 		return ;
// 	push(stk_a, stk_b)
// }