/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo_helper.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 22:29:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 22:37:20 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

unsigned int	get_node_position(t_node *stk, t_node *node)
{
	size_t	i;

	i = 0;
	while (stk && stk != node)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

unsigned int	get_min_move_count(t_node *node, t_stack *stk)
{
	unsigned int	move_count;

	move_count = get_node_position(stk->list, node);
	if (move_count > stk->size / 2)
		move_count = stk->size - move_count;
	return (move_count);
}

void	move_node_to_top(t_stack **stk_a, t_node *lookup)
{
	unsigned int	node_pos;
	bool			node_closer_to_btm;
	t_node			*ptr;

	ptr = (*stk_a)->list;
	if (lookup == NULL)
		return ;
	node_pos = get_node_position((*stk_a)->list, lookup);
	node_closer_to_btm = node_pos > (*stk_a)->size / 2;
	while (ptr != lookup)
	{
		if (node_closer_to_btm)
			rotate(stk_a, true);
		else
			rotate(stk_a, false);
		ptr = (*stk_a)->list;
	}
}

t_node	*get_extreme_val(t_node *stk, int extreme_type)
{
	t_node	*extreme_val_node;
	int		coeff;

	coeff = extreme_type;
	extreme_val_node = stk;
	while (stk)
	{
		if (coeff * stk->val > coeff * extreme_val_node->val)
			extreme_val_node = stk;
		stk = stk->next;
	}
	return (extreme_val_node);
}