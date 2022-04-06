/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/06 18:39:57 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>

void	init_stacks(t_stk *stk)
{
	stk->a.head = NULL;
	stk->b.head = NULL;
}

int	main(int argc, char *argv[])
{
	t_stk		stk;

	if (argc < 2)
		return (EXIT_FAILURE);
	init_stacks(&stk);
	parse_cla(argc, argv, &stk.a);
	printf("%d\n", is_sorted(stk.a.head));
	printf("%zu\n", sllist_size(stk.a.head));
	while (stk.a.head)
	{
		static int i;
		printf("sl_list[%d]: %d\n", i++, *stk.a.head->val);
		stk.a.head = stk.a.head->next;
	}
	return (EXIT_SUCCESS);
}