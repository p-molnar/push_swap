/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/05 14:40:25 by pmolnar       ########   odam.nl         */
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
	t_node		*tmp_stk_ptr;

	tmp_stk_ptr = stk.a;
	if (argc < 2)
		return (EXIT_FAILURE);
	init_stacks(&stk);
	parse_cla(argc, argv, &tmp_stk_ptr);
	printf("tmp_ptr: %p\n", tmp_stk_ptr);
	while (tmp_stk_ptr)
	{
		static int i;
		printf("sl_list[%d]: %d\n", i++, *tmp_stk_ptr->val);
		tmp_stk_ptr = tmp_stk_ptr->next;
	}
	return (EXIT_SUCCESS);
}