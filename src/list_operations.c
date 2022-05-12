/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:44:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/12 15:01:39 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>

#include <stdlib.h>
#include <stdio.h>

t_node	*get_last_node(t_node *head)
{
	t_node	*tmp_ptr;

	tmp_ptr = head;
	while (tmp_ptr && tmp_ptr->next)
		tmp_ptr = tmp_ptr->next;
	return (tmp_ptr);
}

t_node	*get_penultimate_node(t_node *head)
{
	t_node	*last_node;

	last_node = get_last_node(head);
	if (last_node->prev == NULL)
		return head;
	return (last_node->prev);
}

t_node	*create_node(long int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = num;
	node->index = -1;
	node->is_sorted = false;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	append_list(t_node **head, t_node *new_node)
{
	t_node	*last_node;

	if (head && new_node)
	{
		if (*head == NULL)
			*head = new_node;
		else
		{
			last_node = get_last_node(*head);
			last_node->next = new_node;
			new_node->prev = last_node;
		}
	}
}

t_node	*search_val(t_node *head, long int val)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

size_t	get_list_size(t_node *head)
{
	size_t	node_count;	

	node_count = 0;
	while (head)
	{
		node_count++;
		head = head->next;
	}
	return (node_count);
}
