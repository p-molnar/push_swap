/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting_ops.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:19:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/04 13:03:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_OPS_H
# define PS_SORTING_OPS_H

void	swap(t_stack **stk);
void	push(t_stack **stk_1, t_stack **stk_2);
void	rotate(t_stack **stk, bool reverse);

#endif