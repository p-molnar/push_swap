/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack_ops.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 13:42:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:30:25 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_OPS_H
# define PS_STACK_OPS_H

# include <ps_data_types.h>

// stack_operations.c
void	swap(t_stack **stk, bool verbose);
void	push(t_stack **src, t_stack **dst, bool verbose);
void	rotate(t_stack **stk, bool reverse, bool verbose);
void	rotate_both(t_stack **stk_a, t_stack **stk_b, \
					bool reverse, bool verbose);
void	init_stacks(t_stacks *stks);

// stack_operations_util.c
void	update_stk_size(t_stack **stk_1, t_stack **stk_2);
void	do_reverse_rotation(t_stack **stk);
void	do_rotation(t_stack **stk);
t_node	*pop(t_node **stk);
void	separate_stacks(t_stacks *stks);

// stack_preparation_util.c
size_t	get_ordered_node_count(t_node *node, t_node *stk_top);
bool	stk_has_marked_node(t_node *stk);
void	push_closest_marked_node(t_stacks *stks);
size_t	get_false_node_position(t_node *stk, int lookup);

#endif