/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:44:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:21:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

t_node	*get_last_node(t_node *head)
{
	t_node	*tmp_ptr;

	tmp_ptr = head;
	while (tmp_ptr && tmp_ptr->next)
		tmp_ptr = tmp_ptr->next;
	return (tmp_ptr);
}

t_node	*create_node(long data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = data;
	node->index = -1;
	node->is_in_order = false;
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

t_node	*search_node_val(t_node *haystack, long needle)
{
	t_node	*node;

	node = haystack;
	while (node != NULL)
	{
		if (node->val == needle)
			return (node);
		node = node->next;
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
