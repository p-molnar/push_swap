/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_custom_data_types.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:46:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/06 23:04:35 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CUSTOM_DATA_TYPES_H
# define PS_CUSTOM_DATA_TYPES_H

# include <stddef.h>

typedef struct s_node
{
	int				*val;
	struct s_node	*next;
}	t_node;

typedef struct s_sllist
{
	t_node	*head;
	size_t	size;
}	t_sllist;

typedef struct s_stk
{
	t_sllist	a;
	t_sllist	b;
}	t_stk;

#endif