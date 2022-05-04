/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 12:38:00 by pmolnar       ########   odam.nl         */
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
		if (coeff * *stk->val > coeff * *extreme_val_node->val)
			extreme_val_node = stk;
		stk = stk->next;
	}
	return (extreme_val_node);
}

// static int	get_node_position(t_node *stk, t_node *node)
// {
// 	size_t	i;

// 	i = 0;
// 	while (stk && stk != node)
// 	{
// 		i++;
// 		stk = stk->next;
// 	}
// 	return (i);
// }

void	sort_stack_of_size_3(t_stk **stk, size_t stk_size, int order)
{
	t_node	*top;
	t_node	*mid;
	t_node	*btm;

	top = (*stk)->sllist;
	mid = top->next;
	if (mid == NULL)
		mid = top;
	btm	= mid->next;
	if (btm == NULL)
		btm = mid;
	while (!is_stack_sorted((*stk)->sllist, stk_size, order))
	{
		if (order * *top->val > order * *mid->val)
		{
			if (order * *top->val > order * *btm->val)
				rotate(stk, false);
			else if (order * *top->val < order * *btm->val)
				swap(stk);
		}
		else if (order * *top->val < order * *mid->val)
			rotate(stk, true);
		sort_stack_of_size_3(stk, stk_size, order);
	}
}

// void	sort_stack(t_stk **stk_a, t_stk **stk_b, int ordering)
// {
// 	t_node	*min_node = get_extreme_val((*stk_a)->sllist, MIN);
// 	int	min = min_node->val;
// }
