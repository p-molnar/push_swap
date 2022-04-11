/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 17:44:57 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/11 12:16:47 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_custom_data_types.h>
#include <sl_list_ops.h>
#include <stdio.h>

// pop the first node of linked list
static t_node	*pop(t_node **stk)
{
	t_node	*node_1;

	node_1 = *stk;
	*stk = node_1->next;
	return (node_1);
}

void	swap(t_node **stk)
{
	t_node	*node_1;
	t_node	*node_2;
	t_node	*tmp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	node_1 = *stk;
	node_2 = node_1->next;
	tmp = node_2->next;
	node_2->next = node_1;
	node_1->next = tmp;
	*stk = node_2;
}

// push from stk_1 to stk_2
void	push(t_node **stk_1, t_node **stk_2)
{
	t_node	*popped_node;
	bool	is_last_popped_node;

	if (stk_1 == NULL || *stk_1 == NULL)
		return ;
	is_last_popped_node = (get_sllist_size(*stk_1) == 1);
	popped_node = pop(stk_1);
	popped_node->next = *stk_2;
	*stk_2 = popped_node;
	if (is_last_popped_node)
		*stk_1 = NULL;
}

// rotate to the right. first el becomes last and
// second el the first
void	rotate(t_node **stk, bool reverse)
{
	t_node	*node_1;
	t_node	*node_last;
	t_node	*penultimate_node;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return ;
	node_1 = *stk;
	node_last = get_last_node(*stk);
	penultimate_node = get_penultimate_node(*stk);
	if (reverse == true)
	{
		node_last->next = node_1;
		penultimate_node->next = NULL;
		*stk = node_last;
	}
	else
	{
		*stk = node_1->next;
		node_1->next = NULL;
		node_last->next = node_1;
	}
}
