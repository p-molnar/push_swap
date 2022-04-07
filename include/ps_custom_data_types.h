/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_custom_data_types.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:46:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/07 12:51:11 by pmolnar       ########   odam.nl         */
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

#endif