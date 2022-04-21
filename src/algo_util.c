/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_util.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 10:43:38 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/21 10:44:04 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	is_stack_separated(t_node *stk, size_t counter, int criteria)
{
	long int	bit_mask;

	bit_mask = 0b1;
	while (stk)
	{
		if ((*(stk->val) >> counter & bit_mask) != criteria)
			return (false);
		stk = stk->next;
	}
	return (true);
}
