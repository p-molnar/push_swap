/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 10:27:45 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/21 10:29:18 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
