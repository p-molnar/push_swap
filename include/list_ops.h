/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_ops.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:53:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/12 15:42:40 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_LIST_OPS_H
# define SL_LIST_OPS_H

#include <ps_custom_data_types.h>

t_node			*create_node(long int num);
t_node			*get_last_node(t_node *head);
t_node			*get_penultimate_node(t_node *head);
void			append_list(t_node **head, t_node *new_node);
t_node			*search_val(t_node *head, long int val);
unsigned int	get_list_size(t_node *head);
#endif