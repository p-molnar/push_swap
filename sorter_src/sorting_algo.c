/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/31 23:58:16 by pmolnar       ########   odam.nl         */
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
		if (stk_a->val < stk_a->next->val
			&& (node->val > stk_a->val && node->val < stk_a->next->val))
		{
			return (stk_a->next);
		}
		else if (stk_a->val > stk_a->next->val
			&& ((node->val > stk_a->val && node->val > stk_a->next->val)
				|| (node->val < stk_a->val && node->val < stk_a->next->val)))
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

t_node	*get_min_op_count_node(t_stack *stk_a, t_stack *stk_b)
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
			min_node = node_b;
		}
		node_b = node_b->next;
	}
	return (min_node);
}

void	sort_stack(t_stacks *stks, size_t stk_size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_node	*node;

	stk_a = &stks->a;
	stk_b = &stks->b;
	while (is_stack_sorted(stk_a->list, stk_size, ASCENDING) != true)
	{
		separate_stacks(stks);
		while (stk_b->list != NULL)
		{
			node = get_min_op_count_node(stk_a, stk_b);
			move_node_to_top(&stk_b, node, true);
			move_node_to_top(&stk_a, get_matching_node(stk_a, node), true);
			push(&stk_b, &stk_a, true);
		}
		move_node_to_top(&stk_a, get_extreme_val(stk_a->list, MIN), true);
	}
}
