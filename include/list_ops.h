/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_ops.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:53:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/13 23:46:04 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_OPS_H
# define LIST_OPS_H

# include <ps_custom_data_types.h>

t_node			*create_node(long data);
void			append_list(t_node **head, t_node *new_node);
t_node			*get_last_node(t_node *head);
unsigned int	get_list_size(t_node *head);
t_node			*search_node_val(t_node *haystack, long needle);

#endif