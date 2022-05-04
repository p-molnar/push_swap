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


void	update_stk_size(t_stk **stk_1, t_stk **stk_2)
{
	(*stk_1)->size = get_sllist_size((*stk_1)->sllist);
	(*stk_2)->size = get_sllist_size((*stk_2)->sllist);
}

static t_node	*pop(t_node **stk)
{
	t_node	*node;

	node = *stk;
	*stk = node->next;
	return (node);
}

void	push(t_stk **stk_1, t_stk **stk_2)
{
	t_node	*popped_node;
	bool	is_last_popped_node;

	if (stk_1 == NULL || (*stk_1)->sllist == NULL)
		return ;
	is_last_popped_node = ((*stk_1)->size == 1);
	popped_node = pop(&(*stk_1)->sllist);
	popped_node->next = (*stk_2)->sllist;
	(*stk_2)->sllist = popped_node;
	if (is_last_popped_node)
		(*stk_1)->sllist = NULL;
	update_stk_size(stk_1, stk_2);
	printf("p%c\n", (*stk_2)->name);
}

void	swap(t_stk **stk)
{
	t_node	*top;
	t_node	*scnd;
	t_node	*tmp;

	if (stk == NULL || (*stk)->sllist == NULL || (*stk)->sllist->next == NULL)
		return ;
	top = (*stk)->sllist;
	scnd = top->next;
	tmp = scnd->next;
	scnd->next = top;
	top->next = tmp;
	(*stk)->sllist = scnd;
	printf("s%c\n", (*stk)->name);
}

void	rotate(t_stk **stk, bool reverse)
{
	t_node	*top;
	t_node	*btm;
	t_node	*penultimate;

	if (stk == NULL || (*stk)->sllist == NULL || (*stk)->sllist->next == NULL)
		return ;
	top = (*stk)->sllist;
	btm = get_last_node((*stk)->sllist);
	penultimate = get_penultimate_node((*stk)->sllist);
	if (reverse == true)
	{
		btm->next = top;
		penultimate->next = NULL;
		(*stk)->sllist = btm;
	}
	else
	{
		(*stk)->sllist = top->next;
		top->next = NULL;
		btm->next = top;
	}
	if (reverse)
		printf("r");
	printf("r%c\n", (*stk)->name);
}