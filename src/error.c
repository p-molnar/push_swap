/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 17:32:34 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 17:32:36 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

static void	free_nodes(t_stacks *stk)
{
	t_node	*stk_ptr;
	t_node	*next;

	stk_ptr = stk->a.list;
	while (stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
	stk_ptr = stk->b.list;
	while (stk_ptr != NULL)
	{
		next = stk_ptr->next;
		free(stk_ptr);
		stk_ptr = next;
	}
}

void	throw_error(t_stacks *stk, bool is_verbose)
{
	if (is_verbose)
		write(STDERR, "error\n", 6);
	free_nodes(stk);
	exit(EXIT_FAILURE);
}
