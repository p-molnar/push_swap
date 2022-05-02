/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting_ops.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:19:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/02 16:35:05 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_OPS_H
# define PS_SORTING_OPS_H

// void	swap(t_node **stk);
void	swap(t_stk **stk);
void	push(t_stk **stk_1, t_stk **stk_2);
void	rotate(t_stk **stk, bool reverse);
// void	rotate(t_node **stk, bool reverse);

// // char	*sa(t_node **stk_a);
// char	*sb(t_node **stk_b);
// char	*ss(t_node **stk_a, t_node **stk_b);
// char	*pa(t_node **stk_a, t_node **stk_b);
// char	*pb(t_node **stk_a, t_node **stk_b);
// char	*ra(t_node **stk_a);
// char	*rb(t_node **stk_b);
// char	*rr(t_node **stk_a, t_node **stk_b);
// char	*rra(t_node **stk_a);
// char	*rrb(t_node **stk_b);
// char	*rrr(t_node **stk_a, t_node **stk_b);

#endif