/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting_ops.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:19:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/11 11:43:17 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_OPS_H
# define PS_SORTING_OPS_H

void	swap(t_node **stk);
void	push(t_node **stk_1, t_node **stk_2);
void	rotate(t_node **stk, bool reverse);

void	sa(t_node **stk_a);
void	sb(t_node **stk_b);
void	ss(t_node **stk_a, t_node **stk_b);
void	pa(t_node **stk_a, t_node **stk_b);
void	pb(t_node **stk_a, t_node **stk_b);
void	ra(t_node **stk_a);
void	rb(t_node **stk_b);
void	rr(t_node **stk_a, t_node **stk_b);
void	rra(t_node **stk_a);
void	rrb(t_node **stk_b);
void	rrr(t_node **stk_a, t_node **stk_b);

#endif