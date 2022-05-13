/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_indexing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:55:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 23:49:08 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <list_ops.h>

static int	index_of_node(t_node *lookup_val,
			t_node **arr, unsigned int arr_size)
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

static t_node	*get_available_node(t_node *stk,
				t_node **used_nodes, unsigned int size)
{
	while (stk)
	{
		if (index_of_node(stk, used_nodes, size) == -1)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

void	add_indexing(t_stacks *stks)
{
	t_node			**used_nodes;
	t_node			*min_node;
	t_node			*stk;
	unsigned int	i;

	used_nodes = malloc(stks->a.size * sizeof(t_node *));
	if (used_nodes == NULL)
		throw_error(stks, true);
	stk = stks->a.list;
	i = 0;
	while (stks->a.size != i)
	{
		min_node = get_available_node(stk, used_nodes, i);
		while (stk)
		{
			if (index_of_node(stk, used_nodes, i) == -1
				&& stk->val < min_node->val)
				min_node = stk;
			stk = stk->next;
		}
		min_node->index = i;
		used_nodes[i++] = min_node;
		stk = stks->a.list;
	}
}
