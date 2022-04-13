/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_list_ops.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:44:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/12 17:05:12 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>
#include <stdlib.h>

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
	while (tmp)
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

int	index_of(t_node *lookup_val, t_node **arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == lookup_val)
			return (i);
		i++;
	}
	return (-1);
}

void	reindex_list(t_node *stk)
{
	size_t	sllist_size;
	t_node	**changed_nodes;
	int		min;
	size_t	i;
	t_node	*min_node;
	t_node	*tmp;

	tmp = stk;
	i = 0;
	min_node = NULL;
	min = 0;
	sllist_size = get_sllist_size(stk);
	changed_nodes = malloc(sizeof(t_node *) * sllist_size);
	while (i != sllist_size)
	{
		while (stk)
		{
			if (index_of(stk, changed_nodes, i) == -1 && *stk->val < min)
			{
				min_node = stk;
			}
			stk = stk->next;
		}
		*min_node->val = i;
		changed_nodes[i] = stk;
		i++;
		stk = tmp;
		min = 0;
	}
}
