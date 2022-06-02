/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 12:29:20 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:20:59 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>
#include <ft_printf.h>

#define STDERR 2

void	error_handling(t_stacks *stks, bool verbose)
{
	free_nodes(stks);
	if (verbose == true)
		ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
