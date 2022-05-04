/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 10:27:45 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 13:30:39 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stacks(t_stacks *stk)
{
	t_node *stk_a;
	t_node *stk_b;

	stk_a = stk->a.list;	
	stk_b = stk->b.list;	
	printf("-----------+-----------\n");
	printf("%5c%c%5c|%5c%c%5c\n", ' ', 'a', ' ', ' ', 'b', ' ');
	printf("-----------+-----------\n");
	while (stk_a || stk_b)
	{
		if (stk_a)
		{
			printf("%6d", stk_a->val);
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' ');
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6d", stk_b->val);
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
			printf("%6d", stk_a->val);
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' ');
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6d", stk_b->val);
			stk_b = stk_b->next;
		}	
		else
			printf("%6c", ' ');
		printf("\n");
	}
	printf("-----------+-----------\n");
}

void	exec_suitable_sorting(t_stacks *stk)
{
	t_stack *stk_a;
	t_stack *stk_b;

	stk_a = &stk->a;
	stk_b = &stk->b;
	if (is_stack_sorted(stk_a->list, stk_a->size, ASCENDING))
		return ;
	if (stk->a.size <= 3)
		sort_stack_of_size_3(&stk_a, stk_a->size, ASCENDING);
	// else
	// 	sort_stack(&stk_a, &stk_b, ASCENDING);
}