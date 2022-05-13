/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 17:32:34 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 22:14:56 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

void	throw_error(t_stacks *stk, bool verbose)
{
	free_nodes(stk);
	if (verbose)
		write(STDERR, "error\n", 6);
	exit(EXIT_FAILURE);
}
