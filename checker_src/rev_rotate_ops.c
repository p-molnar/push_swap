/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_ops.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 01:01:12 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/18 10:31:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_sorting_ops.h>

void	rra(t_stacks **stks)
{
	t_stack	*stk_a;

	stk_a = &(*stks)->a;
	rotate(&stk_a, true, false);
}

void	rrb(t_stacks **stks)
{
	t_stack	*stk_b;

	stk_b = &(*stks)->b;
	rotate(&stk_b, true, false);
}

void	rrr(t_stacks **stks)
{
	rra(stks);
	rrb(stks);
}
