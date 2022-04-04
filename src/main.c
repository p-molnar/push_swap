/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/04 21:43:19 by pmolnar       ########   odam.nl         */
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
	t_sllist	stk;

	if (argc < 2)
		return (EXIT_FAILURE);
	// init_stacks(&stk);
	parse_cla(argc, argv, stk.a);
	printf("%s\n", (char *)stk.a->content);
	printf("%s\n", (char *)stk.a->next->content);
	printf("%s\n", (char *)stk.a->next->next->content);
	return (EXIT_SUCCESS);
}