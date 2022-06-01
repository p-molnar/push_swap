/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/04 17:32:34 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/01 11:11:14 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

void	error(t_stacks *stks, bool verbose)
{
	free_nodes(stks);
	if (verbose)
		write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
}
