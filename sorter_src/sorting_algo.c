/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 00:09:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>
#include <libft.h>

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

size_t	get_total_op_count(int op_count_a, int op_count_b)
{
	int	total;

	if (op_count_a < 0 && op_count_b < 0)
	{
		total = ft_abs(ft_max_i(2, op_count_a, op_count_b));
		total += ft_abs(op_count_a - op_count_b);
	}
	else if (op_count_a > 0 && op_count_b > 0)
	{
		total = ft_abs(ft_min_i(2, op_count_a, op_count_b));
		total += ft_abs(op_count_a - op_count_b);
	}
	else
		total = ft_abs(op_count_a) + ft_abs(op_count_b);
	return (total);
}

t_node	*get_min_op_count_node(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*tmp;
	t_node	*min_node;
	size_t	total_op_count;
	int		op_count_a;
	int		op_count_b;
	size_t	total_min_op_count;

	tmp = stk_b->list;
	min_node = stk_b->list;
	total_min_op_count = -1;
	while (tmp)
	{
		op_count_b = get_min_op_count(tmp, stk_b);
		op_count_a = get_min_op_count(get_matching_node(stk_a, tmp), stk_a);
		total_op_count = get_total_op_count(op_count_a, op_count_b);
		if (total_op_count < total_min_op_count)
		{
			min_node = tmp;
			total_min_op_count = total_op_count;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

void	rotate_nodes(int op_count_a, int op_count_b, t_stacks *stks)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		val;
	bool	reverse;

	stk_a = &stks->a;
	stk_b = &stks->b;
	reverse = op_count_a < 0 || op_count_b < 0;
	op_count_a = ft_abs(op_count_a);
	op_count_b = ft_abs(op_count_b);
	val = ft_min_i(2, op_count_a, op_count_b);
	while (val-- > 0)
		rotate_both(&stk_a, &stk_b, reverse, VERBOSE);	
	val = ft_min_i(2, op_count_a, op_count_b);
	while (ft_abs(op_count_a--) - ft_abs(val) > 0)
		rotate(&stk_a, reverse, VERBOSE);
	while (ft_abs(op_count_b--) - ft_abs(val) > 0)
		rotate(&stk_b, reverse, VERBOSE);
}

void	get_stacks_in_position(t_stacks *stks, t_node *node)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int	op_count_a;
	int	op_count_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	op_count_a = get_min_op_count(get_matching_node(stk_a, node), stk_a);
	op_count_b = get_min_op_count(node, stk_b);
	if (op_count_a <= 0 && op_count_b <= 0)
	{
		rotate_nodes(op_count_a, op_count_b, stks);	
	}
	else if (op_count_a >= 0 && op_count_b >= 0)
	{
		rotate_nodes(op_count_a, op_count_b, stks);
	}
	else
	{
		move_node_to_top(&stk_b, node, VERBOSE);
		move_node_to_top(&stk_a, get_matching_node(stk_a, node), VERBOSE);
	}
	// print_stacks(stks);
}

void	sort_stack(t_stacks *stks, size_t stk_size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_node	*node;

	stk_a = &stks->a;
	stk_b = &stks->b;
	// print_stacks(stks);
	separate_stacks(stks);
	// print_stacks(stks);
	while (is_stack_sorted(stk_a->list, stk_size, ASCENDING) != true)
	{
		while (stk_b->list != NULL)
		{
			// print_stacks(stks);
			node = get_min_op_count_node(stk_a, stk_b);
			get_stacks_in_position(stks, node);
			// move_node_to_top(&stk_b, node, VERBOSE);
			// move_node_to_top(&stk_a, get_matching_node(stk_a, node), VERBOSE);
			push(&stk_b, &stk_a, VERBOSE);
			// print_stacks(stks);
		}
		move_node_to_top(&stk_a, get_extreme_val(stk_a->list, MIN), VERBOSE);
	}
	// print_stacks(stks);
}
