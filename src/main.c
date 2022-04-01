/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/01 11:27:48 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>

void	init_stacks(t_sllist *stk)
{
	stk->a = NULL;
	stk->b = NULL;
}

int	main(int argc, char *argv[])
{
	t_sllist stk;
	t_list	*next;
	(void) next;
	if (argc < 2)
		return (EXIT_FAILURE);
	init_stacks(&stk);
	parse_cla(argc, argv, &stk);
	// next = stk.a->next;
	// while (next)
	// {
	// 	printf("something's happening\n");
	// 	printf("num: %d\n", (int)stk.a->content);
	// 	next = stk.a->next;
	// }
	return (EXIT_SUCCESS);
}