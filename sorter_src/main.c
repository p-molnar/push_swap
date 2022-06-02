/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:18:23 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	size_t		stk_size;
	t_stacks	stks;

	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_input(&stks);
	stk_size = stks.a.size;
	sort_stack(&stks, stk_size);
	free_nodes(&stks);
	return (EXIT_SUCCESS);
}
