/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:40:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 13:17:37 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>
#include <stdlib.h>
#include <stdbool.h>

// if stk is null, it'll return true! write exception
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting)
{
	size_t	i;
	int		coeff;
	t_node	*curr_node;
	t_node	*next_node;

	if (stk == NULL)
		return (false);
	curr_node = stk;
	coeff = sorting;
	i = 0;
	while (curr_node)
	{
		next_node = curr_node->next;
		if (next_node != NULL)
		{
			if (coeff * (curr_node->val) > coeff * (next_node->val))
				return (false);
		}
		i++;
		curr_node = curr_node->next;
	}
	return (true && i == list_size);
}
