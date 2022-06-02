/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_list_ops.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 13:53:06 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:14:23 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIST_OPS_H
# define PS_LIST_OPS_H

# include <ps_data_types.h>

// list_functions.c
t_node	*get_last_node(t_node *head);
t_node	*create_node(long data);
void	append_list(t_node **head, t_node *new_node);
t_node	*search_node_val(t_node *haystack, long needle);
size_t	get_list_size(t_node *head);
void	index_list(t_stacks *stks);

#endif
