/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 13:29:44 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:23:37 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

static size_t	get_total_op_count(t_node *curr_node, t_stack *stk_a, \
									t_stack *stk_b)
{
	int		op_count_a;
	int		op_count_b;
	size_t	total;

	op_count_a = get_min_op_count(get_matching_node(curr_node, stk_a), stk_a);
	op_count_b = get_min_op_count(curr_node, stk_b);
	if ((op_count_a <= 0 && op_count_b <= 0)
		|| (op_count_a >= 0 && op_count_b >= 0))
	{
		op_count_a = ft_abs(op_count_a);
		op_count_b = ft_abs(op_count_b);
		total = ft_min_i(2, op_count_a, op_count_b);
		total += ft_abs(op_count_a - op_count_b);
	}
	else
		total = ft_abs(op_count_a) + ft_abs(op_count_b);
	return (total);
}

static t_node	*get_min_op_count_node(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*tmp;
	t_node	*min_node;
	size_t	curr_op_count;
	size_t	min_op_count;

	tmp = stk_b->list;
	min_node = stk_b->list;
	min_op_count = -1;
	while (tmp)
	{
		curr_op_count = get_total_op_count(tmp, stk_a, stk_b);
		if (curr_op_count < min_op_count)
		{
			min_node = tmp;
			min_op_count = curr_op_count;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

static void	rotate_stks_to_pos(int op_count_a, int op_count_b, t_stacks *stks)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		val;
	bool	reverse;

	stk_a = &stks->a;
	stk_b = &stks->b;
	reverse = (op_count_a < 0 || op_count_b < 0);
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

static void	align_stacks_to_push_pos(t_stacks *stks, t_node *node)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		op_count_a;
	int		op_count_b;

	stk_a = &stks->a;
	stk_b = &stks->b;
	op_count_a = get_min_op_count(get_matching_node(node, stk_a), stk_a);
	op_count_b = get_min_op_count(node, stk_b);
	if ((op_count_a <= 0 && op_count_b <= 0)
		|| (op_count_a > 0 && op_count_b > 0))
	{
		rotate_stks_to_pos(op_count_a, op_count_b, stks);
	}
	else
	{
		move_node_to_top(&stk_b, node, VERBOSE);
		move_node_to_top(&stk_a, get_matching_node(node, stk_a), VERBOSE);
	}
}

void	sort_stack(t_stacks *stks, size_t stk_size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_node	*min_op_count_node;

	stk_a = &stks->a;
	stk_b = &stks->b;
	separate_stacks(stks);
	while (is_stack_sorted(stk_a->list, stk_size, ASCENDING) != true)
	{
		while (stk_b->list != NULL)
		{
			min_op_count_node = get_min_op_count_node(stk_a, stk_b);
			align_stacks_to_push_pos(stks, min_op_count_node);
			push(&stk_b, &stk_a, VERBOSE);
		}
		move_node_to_top(&stk_a, get_extreme_val_node(stk_a->list, MIN), \
						VERBOSE);
	}
}
