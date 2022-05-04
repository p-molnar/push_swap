/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_custom_data_types.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:46:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 12:38:38 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CUSTOM_DATA_TYPES_H
# define PS_CUSTOM_DATA_TYPES_H

# include <stddef.h>

typedef struct s_node
{
	int				*val;
	int				*index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stk
{
	t_node			*sllist;
	unsigned int	size;
	char			name;
}	t_stk;

typedef struct s_stks
{
	t_stk	a;
	t_stk	b;
}	t_stks;

#endif