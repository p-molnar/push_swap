/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sorting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 15:40:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/06 16:08:00 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ps_custom_data_types.h>
#include <stdlib.h>
#include <stdbool.h>

// if stk is null, it'll return ture!

bool	is_sorted(t_node *stk)
{
	t_node	*curr_node;
	t_node	*next_node;
	
	curr_node = stk;
	while (curr_node)
	{
		next_node = curr_node->next;
		if (next_node != NULL)
		{
			if (*curr_node->val > *next_node->val)
				return (false);
		}
		curr_node = curr_node->next;
	}
	return (true);
}