/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/19 01:20:44 by pmolnar       ########   odam.nl         */
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

int	get_total_move_count(t_stack *stk_a, t_stack *stk_b, long *arr)
{
	int	i = 0;
	int	len = stk_b->size;
	int	move_count_a = 0;
	int	move_count_b = 0;
	t_node *node;

	while (i < len)
	{	
		node = search_node_val(stk_b->list, arr[i++]);
		move_count_b += get_min_move_count(node, stk_b);
		move_node_to_top(&stk_b, node);
		move_count_a += get_min_move_count(get_matching_node(stk_a, node), stk_a);
		move_node_to_top(&stk_a, get_matching_node(stk_a, node));
		push(&stk_b, &stk_a, false);
	}
	return (move_count_a + move_count_b);
}

// protect malloc!
void	test_combinations(t_stack *stk_a, t_stack *stk_b)
{
	long		*arr;
	int			i = 0;
	t_node		*ptr;
	int			total = 0;

	arr = malloc(sizeof(long) * stk_b->size);
	ptr = stk_b->list;
	while (ptr)
	{
		arr[i++] = ptr->val;
		ptr = ptr->next;
	}
	int	j, n, temp;
	n = stk_b->size;
	for (j = 1; j <= n; j++) {
		for (i = 0; i < n-1; i++) {
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			total = get_total_move_count(stk_a, stk_b, arr);
			printf("total: %i\n", total);
		}
	}
}

void	retain_sort(t_stacks *stks, int stk_size)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	// t_node	*node;
	(void) stk_size;
	stk_a = &stks->a;
	stk_b = &stks->b;
	prepare_stacks_for_sorting(stks);
	test_combinations(stk_a, stk_b);
	// while (is_stack_sorted(stk_a->list, stk_size, ASCENDING) != true)
	// {
	// 	prepare_stacks_for_sorting(stks);
	// 	while (stk_b->list != NULL)
	// 	{
	// 		node = get_min_op_count_node(stk_a, stk_b);
	// 		move_node_to_top(&stk_b, node);
	// 		move_node_to_top(&stk_a, get_matching_node(stk_a, node));
	// 		push(&stk_b, &stk_a, true);
	// 	}
	// 	move_node_to_top(&stk_a, get_extreme_val(stk_a->list, MIN));
	// }
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
				rotate(stk, false, true);
			else if (order * top->val < order * btm->val)
				swap(stk, true);
		}
		else if (order * top->val < order * mid->val)
			rotate(stk, true, true);
		sort_stack_of_size_3(stk, stk_size, order);
	}
}