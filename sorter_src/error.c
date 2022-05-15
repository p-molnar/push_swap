/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 17:32:34 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/16 00:28:21 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

void	throw_error(t_stacks *stk, bool verbose)
{
	free_nodes(stk);
	if (verbose)
		write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
}
