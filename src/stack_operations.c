/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:52:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/02 15:13: by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <push_swap.h>
#include <ps_sorting_ops.h>


void	update_stk_size(t_stack **stk_1, t_stack **stk_2)
{
	(*stk_1)->size = get_sllist_size((*stk_1)->list);
	(*stk_2)->size = get_sllist_size((*stk_2)->list);
}

static t_node	*pop(t_node **stk)
{
	t_node	*node;

	node = *stk;
	*stk = node->next;
	(*stk)->prev = NULL;
	return (node);
}

void	push(t_stack **stk_1, t_stack **stk_2)
{
	t_node	*popped_node;
	bool	is_last_popped_node;

	if (stk_1 == NULL || (*stk_1)->list == NULL)
		return ;
	is_last_popped_node = ((*stk_1)->size == 1);
	popped_node = pop(&(*stk_1)->list);
	popped_node->next = (*stk_2)->list;
	(*stk_2)->list = popped_node;
	if (is_last_popped_node)
		(*stk_1)->list = NULL;
	update_stk_size(stk_1, stk_2);
	printf("p%c\n", (*stk_2)->name);
}

void	swap(t_stack **stk)
{
	t_node	*top;
	t_node	*scnd;
	t_node	*tmp;

	if (stk == NULL || (*stk)->list == NULL || (*stk)->list->next == NULL)
		return ;
	top = (*stk)->list;
	scnd = top->next;
	tmp = scnd->next;
	scnd->next = top;
	top->next = tmp;
	(*stk)->list = scnd;
	printf("s%c\n", (*stk)->name);
}

void	rotate(t_stack **stk, bool reverse)
{
	t_node	*top;
	t_node	*btm;
	t_node	*penultimate;

	if (stk == NULL || (*stk)->list == NULL || (*stk)->list->next == NULL)
		return ;
	top = (*stk)->list;
	btm = get_last_node((*stk)->list);
	penultimate = get_penultimate_node((*stk)->list);
	if (reverse == true)
	{
		btm->next = top;
		penultimate->next = NULL;
		(*stk)->list = btm;
	}
	else
	{
		(*stk)->list = top->next;
		top->next = NULL;
		btm->next = top;
	}
	if (reverse)
		printf("r");
	printf("r%c\n", (*stk)->name);
}