/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_ops.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 00:44:48 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/17 01:08:07 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_sorting_ops.h>
#include <push_swap.h>

void	sa(t_stacks **stks)
{
	t_stack	*stk_a;

	stk_a = &(*stks)->a;
	swap(&stk_a, false);
}

void	sb(t_stacks **stks)
{
	t_stack	*stk_b;

	stk_b = &(*stks)->b;
	swap(&stk_b, false);
}

void	ss(t_stacks **stks)
{
	sa(stks);
	sb(stks);
}