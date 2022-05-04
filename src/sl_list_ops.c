/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_list_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:44:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 17:23:08 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>

#include <stdlib.h>
#include <stdio.h>

t_node	*get_last_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*get_penultimate_node(t_node *head)
{
	t_node	*curr_node;
	t_node	*last_node;

	curr_node = head;
	last_node = get_last_node(head);
	while (curr_node->next != last_node)
		curr_node = curr_node->next;
	return (curr_node);
}

t_node	*create_node(long int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = num;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	append_list(t_node **head, t_node *new_node)
{
	t_node	*last_node;

	if (head && new_node)
	{
		if (!*head)
			*head = new_node;
		else
		{
			last_node = get_last_node(*head);
			last_node->next = new_node;
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

size_t	get_sllist_size(t_node *head)
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
