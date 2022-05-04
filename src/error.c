/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 16:01:23 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 13:11:55by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

static void	free_nodes(t_stacks *stk)
{
	t_node *stk_ptr;
	t_node *next;
	
	stk_ptr = stk->a.list;
	while(stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
	stk_ptr = stk->b.list;
	while(stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
}

void	throw_error(t_stacks *stk)
{
	const char *error_msg = "error\n";
	write(STDERR, error_msg, ft_strlen(error_msg));
	free_nodes(stk);
	exit(EXIT_FAILURE);
}