/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_nodes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 22:13:07 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:17:45 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

void	free_nodes(t_stacks *stks)
{
	t_node	*stk_ptr;
	t_node	*next;

	stk_ptr = stks->a.list;
	while (stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
	stk_ptr = stks->b.list;
	while (stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
}
