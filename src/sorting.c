/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 16:59:16 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 00:11:44 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_custom_data_types.h>

void	sort_stacks(t_stacks *stks, int stk_size)
{
	t_stack	*stk_a;

	stk_a = &stks->a;
	if (stks->a.size <= 3)
		sort_stack_of_size_3(&stk_a, stk_size, ASCENDING);
	else
		retain_sort(stks, stk_size);
}