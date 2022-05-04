/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 13:02:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>
#include <ps_sorting_ops.h>

void	init_stacks(t_stacks *stks)
{
	stks->a.list = NULL;
	stks->b.list = NULL;
}

int	main(int argc, char *argv[])
{
	t_stacks	stks;

	parse_input(argc, argv, &stks);
	print_stacks(&stks);
	// stk.a.size = get_sllist_size(stk.a.sllist);
	// print_stacks(&stk);
	// rebase_list(stk.a.sllist);
	// print_stacks(&stk);
	// t_stk	*stk_a = &stk.a;
	// t_stk	*stk_b = &stk.b;
	// exec_suitable_sorting(&stk);
	// print_stacks(stk_a, stk_b);
	return (EXIT_SUCCESS);
}
