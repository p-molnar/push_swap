/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_list_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:44:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/02 21:43:06 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>

#include <stdlib.h>
#include <stdio.h>

t_node	*get_last_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp->next && tmp)
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

t_node *create_node(int num)
{
	t_node	*node;
	int		*num_cpy;

	node = malloc(sizeof(t_node));
	num_cpy = malloc(sizeof(int));
	if (!node || !num_cpy)
		return (NULL);
	*num_cpy = num;
	node->val = num_cpy;
	node->index = NULL;
	node->next = NULL;
	return (node);
}

void	sllist_append(t_node **head, t_node *new_node)
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

t_node	*sllist_search(t_node *head, int val)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (*tmp->val == val)
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
