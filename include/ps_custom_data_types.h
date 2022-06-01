/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_custom_data_types.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:46:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/01 13:28:25 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CUSTOM_DATA_TYPES_H
# define PS_CUSTOM_DATA_TYPES_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_node
{
	bool			is_sorted;
	long int		val;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*list;
	size_t			size;
	char			name;
	size_t			total_op_count;

}	t_stack;

typedef struct s_stacks
{
	t_stack			a;
	t_stack			b;
}	t_stacks;

#endif