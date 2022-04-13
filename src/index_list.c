/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:55:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/13 19:35:43 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <sl_list_ops.h>

#include <stdio.h>

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

t_node	*get_available_node(t_node *stk, t_node **used_nodes, size_t size)
{
	while (stk)
	{
		if (index_of(stk, used_nodes, size) == -1)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}


// protect malloc !
void	index_list(t_node *stk)
{
	t_node	**used_nodes;
	t_node	*min_node;
	t_node	*tmp;
	size_t	list_size;
	size_t	i;

	list_size = get_sllist_size(stk);
	used_nodes = malloc(list_size * sizeof(t_node *));
	tmp = stk;
	i = 0;
	while (i != list_size)
	{
		min_node = get_available_node(stk, used_nodes, i);
		while (stk)
		{
			if (index_of(stk, used_nodes, i) == -1
				&& *stk->val < *min_node->val)
				min_node = stk;
			stk = stk->next;
		}
		*min_node->val = i;
		used_nodes[i++] = min_node;
		stk = tmp;
	}
}
