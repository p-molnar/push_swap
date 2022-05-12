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
	(*stk_1)->size = get_list_size((*stk_1)->list);
	(*stk_2)->size = get_list_size((*stk_2)->list);
}

static t_node	*pop(t_node **stk)
{
	t_node	*node;

	node = *stk;
	*stk = (*stk)->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push(t_stack **src, t_stack **dst)
{
	t_node	*popped_node;

	if (src == NULL || (*src)->list == NULL)
		return ;
	popped_node = pop(&(*src)->list);
	popped_node->next = (*dst)->list;
	(*dst)->list = popped_node;
	if (popped_node->next != NULL)
		popped_node->next->prev = popped_node;
	update_stk_size(src, dst);
	printf("p%c\n", (*dst)->name);
}

void	swap(t_stack **stk)
{
	t_node	*node_1;
	t_node	*node_2;
	t_node	*node_3;

	if (stk == NULL || (*stk)->list == NULL || (*stk)->list->next == NULL)
		return ;
	node_1 = (*stk)->list;
	node_2 = node_1->next;
	node_3 = node_2->next;
	node_1->next = node_3;
	node_1->prev = node_2;
	if (node_3 != NULL)
		node_3->prev = node_1;
	node_2->next = node_1;
	node_2->prev = NULL;
	(*stk)->list = node_2;
	printf("s%c\n", (*stk)->name);
}

void	rotate(t_stack **stk, bool reverse)
{
	t_node	*node_1;
	t_node	*node_n;
	t_node	*node_n_1;

	if (stk == NULL || (*stk)->list == NULL || (*stk)->list->next == NULL)
		return ;
	node_1 = (*stk)->list;
	node_n = get_last_node((*stk)->list);
	node_n_1 = node_n->prev;
	if (reverse == true)
	{
		node_n->next = node_1;
		node_n->prev = NULL;
		node_1->prev = node_n;
		if (node_n_1 != NULL)
			node_n_1->next = NULL;
		(*stk)->list = node_n;
	}
	else if (reverse == false)
	{
		(*stk)->list = node_1->next;
		(*stk)->list->prev = NULL;
		node_1->next = NULL;
		node_n->next = node_1;
		node_1->prev = node_n;
	}
	if (reverse == true)
		printf("r");
	printf("r%c\n", (*stk)->name);
}