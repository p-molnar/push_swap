/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:52:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/07 18:11:32 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <push_swap.h>
#include <ps_sorting_ops.h>

void	sa(t_node **stk_a)
{
	swap(stk_a);
	write(1, "sa\n", 3);
}

void	sb(t_node **stk_b)
{
	swap(stk_b);
	write(1, "sb\n", 3);
}

void	ss(t_node **stk_a, t_node **stk_b)
{
	sa(stk_a);
	sb(stk_b);
	write(1, "ss\n", 3);
}

void	pa(t_node **stk_a, t_node **stk_b)
{
	push(stk_b, stk_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **stk_a, t_node **stk_b)
{
	push(stk_a, stk_b);
	write(1, "pb\n", 3);
}

void	ra(t_node **stk_a)
{
	rotate(stk_a, false);
	write(1, "ra\n", 3);
}

void	rb(t_node **stk_b)
{
	rotate(stk_b, false);
	write(1, "rb\n", 3);
}

void	rr(t_node **stk_a, t_node **stk_b)
{
	ra(stk_a);
	rb(stk_b);
	write(1, "rr\n", 3);
}

void	rra(t_node **stk_a)
{
	rotate(stk_a, true);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stk_b)
{
	rotate(stk_b, true);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stk_a, t_node **stk_b)
{
	rra(stk_a);
	rrb(stk_b);
	write(1, "rrr\n", 4);
}