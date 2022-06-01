/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_ops.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 00:51:25 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 00:59:58 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_sorting_ops.h>

void	pa(t_stacks **stks)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = &(*stks)->a;
	stk_b = &(*stks)->b;
	push(&stk_b, &stk_a, SILENT);
}

void	pb(t_stacks **stks)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = &(*stks)->a;
	stk_b = &(*stks)->b;
	push(&stk_a, &stk_b, SILENT);
}
