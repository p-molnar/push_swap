/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting_ops.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 11:19:22 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/17 01:07:41 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORTING_OPS_H
# define PS_SORTING_OPS_H

# include <push_swap.h>

void	swap(t_stack **stk, bool verbose);
void	push(t_stack **src, t_stack **dst, bool verbose);
void	rotate(t_stack **stk, bool reverse, bool verbose);

#endif