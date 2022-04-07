/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/07 20:09:36 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>
#include <ps_sorting_ops.h>

void	print_stacks(t_node *stk_a, t_node *stk_b)
{
	printf("-----------+-----------\n");
	printf("%5c%c%5c|%5c%c%5c\n", ' ', 'a', ' ', ' ', 'b', ' ');
	printf("-----------+-----------\n");
	while (stk_a || stk_b)
	{
		if (stk_a)
		{
			printf("%6d", *stk_a->val); 
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' '); 
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6d", *stk_b->val);
			stk_b = stk_b->next;
		}	
		else
			printf("%6c", ' '); 
		printf("\n");
	}
	printf("-----------+-----------\n");
}
int	main(int argc, char *argv[])
{
	t_node	*stk_a;
	t_node	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	parse_cla(argc, argv, &stk_a);
	printf("sorted = %d\n", is_sorted(stk_a));
	return (EXIT_SUCCESS);
}
