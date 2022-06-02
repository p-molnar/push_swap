/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_algo_util.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 13:48:28 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:18:42 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*get_matching_node(t_node *node_to_match, t_stack *stk)
{
	t_node	*stk_a;

	stk_a = stk->list;
	while (stk_a)
	{
		if (stk_a->val < stk_a->next->val \
			&& (node_to_match->val > stk_a->val \
			&& node_to_match->val < stk_a->next->val))
		{
			return (stk_a->next);
		}
		else if (stk_a->val > stk_a->next->val \
			&& ((node_to_match->val > stk_a->val \
			&& node_to_match->val > stk_a->next->val) \
			|| (node_to_match->val < stk_a->val \
			&& node_to_match->val < stk_a->next->val)))
		{
			return (stk_a->next);
		}
		if (stk_a->next->next != NULL)
			stk_a = stk_a->next;
		else
			break ;
	}
	return (stk->list);
}

size_t	get_node_index(t_node *stk, t_node *node)
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

int	get_min_op_count(t_node *node, t_stack *stk)
{
	int	op_count;

	op_count = get_node_index(stk->list, node);
	if (op_count > (int) stk->size / 2)
		op_count = -(stk->size - op_count);
	return (op_count);
}

void	move_node_to_top(t_stack **stk, t_node *node, bool verbose)
{
	unsigned int	node_pos;
	bool			node_closer_to_btm;
	t_node			*ptr;

	ptr = (*stk)->list;
	if (node == NULL)
		return ;
	node_pos = get_node_index((*stk)->list, node);
	node_closer_to_btm = node_pos > (*stk)->size / 2;
	while (ptr != node)
	{
		if (node_closer_to_btm)
			rotate(stk, true, verbose);
		else
			rotate(stk, false, verbose);
		ptr = (*stk)->list;
	}
}

t_node	*get_extreme_val_node(t_node *stk, int extreme_type)
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
