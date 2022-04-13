/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:52:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/13 21:34:01 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <push_swap.h>
#include <ps_sorting_ops.h>

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_node **stk_a)
{
	swap(stk_a);
	// write(1, "sa\n", 3);
	printf("sa\n");
	
}

// sb (swap b): Swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements.
void	sb(t_node **stk_b)
{
	swap(stk_b);
	// write(1, "sb\n", 3);
	printf("sb\n");
}

// ss : sa and sb at the same time.
void	ss(t_node **stk_a, t_node **stk_b)
{
	sa(stk_a);
	sb(stk_b);
	// write(1, "ss\n", 3);
	printf("ss\n");
}

// pa (push a): Take the first element at the top of b 
// and put it at the top of a. Do nothing if b is empty.
void	pa(t_node **stk_a, t_node **stk_b)
{
	push(stk_b, stk_a);
	// write(1, "pa\n", 3);
	printf("pa\n");
}

// pb (push b): Take the first element at the top of a 
// and put it at the top of b. Do nothing if a is empty.
void	pb(t_node **stk_a, t_node **stk_b)
{
	push(stk_a, stk_b);
	// write(1, "pb\n", 3);
	printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	ra(t_node **stk_a)
{
	rotate(stk_a, false);
	// write(1, "ra\n", 3);
	printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1. 
// The first element becomes the last one.
void	rb(t_node **stk_b)
{
	rotate(stk_b, false);
	// write(1, "rb\n", 3);
	printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_node **stk_a, t_node **stk_b)
{
	ra(stk_a);
	rb(stk_b);
	// write(1, "rr\n", 3);
	printf("rr\n");
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_node **stk_a)
{
	rotate(stk_a, true);
	// write(1, "rra\n", 4);
	printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. 
void	rrb(t_node **stk_b)
{
	rotate(stk_b, true);
	// write(1, "rrb\n", 4);
	printf("rrb\n");
}

// rrr : rra and rrb at the same time.
void	rrr(t_node **stk_a, t_node **stk_b)
{
	rra(stk_a);
	rrb(stk_b);
	// write(1, "rrr\n", 4);
	printf("rrr\n");
}
