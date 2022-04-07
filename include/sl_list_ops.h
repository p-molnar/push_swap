/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_list_ops.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:53:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/07 15:55:13 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_LIST_OPS_H
# define SL_LIST_OPS_H

#include <ps_custom_data_types.h>

t_node	*create_node(int num);
t_node	*get_last_node(t_node *head);
t_node	*get_penultimate_node(t_node *head);
void	sllist_append(t_node **head, t_node *new_node);
t_node	*sllist_search(t_node *head, int val);
size_t	get_sllist_size(t_node *head);

#endif