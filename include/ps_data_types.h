/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_data_types.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:46:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 11:38:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_DATA_TYPES_H
# define PS_DATA_TYPES_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_node
{
	bool			is_in_order;
	long int		val;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*list;
	size_t			size;
	char			name;

}	t_stack;

typedef struct s_stacks
{
	t_stack			a;
	t_stack			b;
}	t_stacks;

#endif