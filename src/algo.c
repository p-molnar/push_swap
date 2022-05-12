/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 00:47:27 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

t_node	*get_extreme_val(t_node *stk, int extreme_type)
{
	t_node	*extreme_val_node;
	int		coeff;

	coeff = extreme_type;
	extreme_val_node = stk;
	while (stk)
	{
		if (coeff * stk->val > coeff * extreme_val_node->val)
			extreme_val_node = stk;
		stk = stk->next;
	}
	return (extreme_val_node);
}

static int	get_node_position(t_node *stk, t_node *node)
{
	size_t	i;

	i = 0;
	while (stk && stk != node)
	{
		i++;
		stk = stk->next;
	}
	return (i);
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
	btm	= mid->next;
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
			break;
	}
	return (stk->list);
}

unsigned int	get_min_move_count(t_node *node, t_stack *stk)
{
	unsigned int	move_count;

	move_count = get_node_position(stk->list, node);
	if (move_count > stk->size / 2)
		move_count = stk->size - move_count;
	return (move_count);
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
			printf("min_move_a: %u\n", min_move_count_a);
			printf("min_move_b: %u\n", min_move_count_b);
			min_node = node_b;
		}
		node_b = node_b->next;
	}
	return (min_node);
}

void	get_node_to_top(t_stack **stk_a, t_node *lookup)
{
	unsigned int	node_pos;
	bool			node_closer_to_btm;
	t_node			*ptr;

	ptr = (*stk_a)->list;
	if (lookup == NULL)
		return ;
	node_pos = get_node_position((*stk_a)->list, lookup);
	node_closer_to_btm = node_pos > (*stk_a)->size / 2;
	while (ptr != lookup)
	{
		if (node_closer_to_btm)
			rotate(stk_a, true);
		else
			rotate(stk_a, false);
		ptr = (*stk_a)->list;
	}
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
		prepare_stacks_for_retain_sorting(stks);
		print_stacks(stks);
		while (stk_b->list != NULL)
		{
			node = get_min_op_count_node(stk_a, stk_b);
			if (node)
				printf("min_node: %ld\n", node->val);
			get_node_to_top(&stk_b, node);
			get_node_to_top(&stk_a, get_matching_node(stk_a, node));
			push(&stk_b, &stk_a);
			print_stacks(stks);
		}
		get_node_to_top(&stk_a, get_extreme_val(stk_a->list, MIN));
	}
}