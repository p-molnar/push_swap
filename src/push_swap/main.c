/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/06 12:03:27 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_stacks	stks;

	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_input(&stks);
	sort_stack(&stks, stks.a.size);
	free_nodes(&stks);
	return (EXIT_SUCCESS);
}
