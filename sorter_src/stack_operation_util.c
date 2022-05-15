/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_operation_util.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/14 00:28:53 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/14 19:13:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	update_stk_size(t_stack **stk_1, t_stack **stk_2)
{
	(*stk_1)->size = get_list_size((*stk_1)->list);
	(*stk_2)->size = get_list_size((*stk_2)->list);
}

t_node	*pop(t_node **stk)
{
	t_node	*node;

	node = *stk;
	*stk = (*stk)->next;
	if (*stk != NULL)
		(*stk)->prev = NULL;
	node->next = NULL;
	return (node);
}

void	do_reverse_rotation(t_stack **stk)
{
	t_node	*node_1;
	t_node	*node_n;
	t_node	*node_n_1;

	node_1 = (*stk)->list;
	node_n = get_last_node((*stk)->list);
	node_n_1 = node_n->prev;
	node_n->next = node_1;
	node_n->prev = NULL;
	node_1->prev = node_n;
	if (node_n_1 != NULL)
		node_n_1->next = NULL;
	(*stk)->list = node_n;
}

void	do_rotation(t_stack **stk)
{
	t_node	*node_1;
	t_node	*node_n;
	t_node	*node_n_1;

	node_1 = (*stk)->list;
	node_n = get_last_node((*stk)->list);
	node_n_1 = node_n->prev;
	(*stk)->list = node_1->next;
	(*stk)->list->prev = NULL;
	node_1->next = NULL;
	node_n->next = node_1;
	node_1->prev = node_n;
}
