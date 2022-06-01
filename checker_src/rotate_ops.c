/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_ops.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 00:55:13 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 01:01:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_sorting_ops.h>

void	ra(t_stacks **stks)
{
	t_stack	*stk_a;

	stk_a = &(*stks)->a;
	rotate(&stk_a, NO_REVERSE, SILENT);
}

void	rb(t_stacks **stks)
{
	t_stack	*stk_b;

	stk_b = &(*stks)->b;
	rotate(&stk_b, NO_REVERSE, SILENT);
}

void	rr(t_stacks **stks)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = &(*stks)->b;
	stk_b = &(*stks)->b;
	rotate_both(&stk_a, &stk_b, NO_REVERSE, SILENT);
}
