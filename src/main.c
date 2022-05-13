/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/14 00:31:40 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>
#include <ps_sorting_ops.h>

void	print_stacks(t_stacks *stk)
{
	t_node	*stk_a;
	t_node	*stk_b;

	stk_a = stk->a.list;
	stk_b = stk->b.list;
	printf("-----------+-----------\n");
	printf("%5c%c%5c|%5c%c%5c\n", ' ', 'a', ' ', ' ', 'b', ' ');
	printf("-----------+-----------\n");
	while (stk_a|| stk_b)
	{
		if (stk_a)
		{
			printf("%6ld", stk_a->val);
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' ');
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6ld", stk_b->val);
			stk_b = stk_b->next;
		}	
		else
			printf("%6c", ' ');
		printf("\n");
	}
	printf("-----------+-----------\n");
}

void	print_stacks_2(t_stack *stk_1, t_stack *stk_2)
{
	t_node *stk_a = stk_1->list;
	t_node *stk_b = stk_2->list;

	printf("-----------+-----------\n");
	printf("%5c%c%5c|%5c%c%5c\n", ' ', 'a', ' ', ' ', 'b', ' ');
	printf("-----------+-----------\n");
	while (stk_a || stk_b)
	{
		if (stk_a)
		{
			printf("%6ld", stk_a->val);
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' ');
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6ld", stk_b->val);
			stk_b = stk_b->next;
		}	
		else
			printf("%6c", ' ');
		printf("\n");
	}
	printf("-----------+-----------\n");
}

static void	init_stacks(t_stacks *stks)
{
	stks->a.list = NULL;
	stks->a.name = 'a';
	stks->b.list = NULL;
	stks->b.name = 'b';
}

int	main(int argc, char *argv[])
{
	unsigned int	stk_size;
	t_stacks		stks;
	t_stack			*stk_a;
	t_stack			*stk_b;

	stk_a = &stks.a;
	stk_b = &stks.b;
	stk_size = argc - 1;
	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_data(&stks);
	// print_stacks(&stks);
	if (stk_a->size <= 3)
		sort_stack_of_size_3(&stk_a, stk_size, ASCENDING);
	else
		retain_sort(&stks, stk_size);
	free_nodes(&stks);
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
