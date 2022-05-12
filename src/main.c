/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 01:14:50 by pmolnar       ########   odam.nl         */
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
	stks->a.name = 'a';
	stks->b.list = NULL;
	stks->b.name = 'b';
}

int	main(int argc, char *argv[])
{
	t_stacks	stks;
	t_stack		*stk_a;
	t_stack		*stk_b;

	stk_a = &stks.a;
	stk_b = &stks.b;
	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_data(&stks);
	// print_stacks(&stks);
	sort_stacks(&stks, argc - 1);
	// print_stacks(&stks);
	// while (1)
	// {
	// 	if (rand() % 2)
	// 	{
	// 		if (rand() % 2)
	// 			rotate(&stk_a, true);
	// 		else
	// 		{
	// 			if (rand() % 2)
	// 				rotate(&stk_a, false);
	// 			else
	// 			{
	// 				if (rand() % 2)
	// 					swap(&stk_a);
	// 				else
	// 					swap(&stk_b);
	// 			}	
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (rand() % 2)
	// 			rotate(&stk_b, true);
	// 		else	
	// 		{
	// 			if (rand() % 2)
	// 				rotate(&stk_b, false);
	// 			else
	// 			{
	// 				if (rand() % 2)
	// 					push(&stk_a, &stk_b);
	// 				else
	// 					push(&stk_b, &stk_a);
	// 			}	
	// 		}
	// 	}
	// 	sleep(1);
	// 	print_stacks(&stks);
	// }
	// swap(&stk_a);
	// print_stacks(&stks);
	// swap(&stk_a);
	// print_stacks(&stks);
	// swap(&stk_a);
	// print_stacks(&stks);
	// stk_a.a.size = get_list_size(stk.a.sllist);
	// print_stacks(&stk);
	// add_indexing(stk.a.sllist);
	// print_stacks(&stk);
	// t_stk	*stk_a = &stk.a;
	// t_stk	*stk_b = &stk.b;
	// exec_suitable_sorting(&stk);
	// print_stacks(stk_a, stk_b);
	return (EXIT_SUCCESS);
}
