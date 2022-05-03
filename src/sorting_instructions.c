/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:52:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/02 15:13: by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <push_swap.h>
#include <ps_sorting_ops.h>

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// char	*s(t_stk **stk)
// {
// 	t_node	*sllist;

// 	sllist = (*stk)->sllist;
// 	swap(&sllist);
// 	printf("s%c\n", (*stk)->name);
// 	return("sa\n");
// }

void	update_stk_size(t_stk **stk_1, t_stk **stk_2)
{
	(*stk_1)->size = get_sllist_size((*stk_1)->sllist);
	(*stk_2)->size = get_sllist_size((*stk_2)->sllist);
}

static t_node	*pop(t_node **stk)
{
	t_node	*node;

	node = *stk;
	*stk = node->next;
	return (node);
}

void	push(t_stk **stk_1, t_stk **stk_2)
{
	t_node	*popped_node;
	bool	is_last_popped_node;

	if (stk_1 == NULL || (*stk_1)->sllist == NULL)
		return ;
	is_last_popped_node = ((*stk_1)->size == 1);
	popped_node = pop(&(*stk_1)->sllist);
	popped_node->next = (*stk_2)->sllist;
	(*stk_2)->sllist = popped_node;
	if (is_last_popped_node)
		(*stk_1)->sllist = NULL;
	update_stk_size(stk_1, stk_2);
	printf("p%c\n", (*stk_2)->name);
}

void	swap(t_stk **stk)
{
	t_node	*top;
	t_node	*scnd;
	t_node	*tmp;

	if (stk == NULL || (*stk)->sllist == NULL || (*stk)->sllist->next == NULL)
		return ;
	top = (*stk)->sllist;
	scnd = top->next;
	tmp = scnd->next;
	scnd->next = top;
	top->next = tmp;
	(*stk)->sllist = scnd;
	printf("s%c\n", (*stk)->name);
}

void	rotate(t_stk **stk, bool reverse)
{
	t_node	*top;
	t_node	*btm;
	t_node	*penultimate;

	if (stk == NULL || (*stk)->sllist == NULL || (*stk)->sllist->next == NULL)
		return ;
	top = (*stk)->sllist;
	btm = get_last_node((*stk)->sllist);
	penultimate = get_penultimate_node((*stk)->sllist);
	if (reverse == true)
	{
		btm->next = top;
		penultimate->next = NULL;
		(*stk)->sllist = btm;
	}
	else
	{
		(*stk)->sllist = top->next;
		top->next = NULL;
		btm->next = top;
	}
	if (reverse)
		printf("r");
	printf("r%c\n", (*stk)->name);
}
// // sb (swap b): Swap the first 2 elements at the top of stack b. 
// // Do nothing if there is only one or no elements.
// char	*sb(t_node **stk_b)
// {
// 	swap(stk_b);
// 	// write(1, "sb\n", 3);
// 	printf("sb\n");
// 	return("sb\n");
// }

// ss : sa and sb at the same time.
// char	*ss(t_node **stk_a, t_node **stk_b)
// {
// 	sa(stk_a);
// 	sb(stk_b);
// 	// write(1, "ss\n", 3);
// 	printf("ss\n");
// 	return("ss\n");
// }

// pa (push a): Take the first element at the top of b 
// and put it at the top of a. Do nothing if b is empty.
// char	*pa(t_node **stk_a, t_node **stk_b)
// {
// 	push(stk_b, stk_a);
// 	// write(1, "pa\n", 3);
// 	printf("pa\n");
// 	return("pa\n");
// }

// pb (push b): Take the first element at the top of a 
// and put it at the top of b. Do nothing if a is empty.
// char	*pb(t_node **stk_a, t_node **stk_b)
// {
// 	push(stk_a, stk_b);
// 	// write(1, "pb\n", 3);
// 	printf("pb\n");
// 	return("pb\n");
// }

// ra (rotate a): Shift up all elements of stack a by 1. 
// The first element becomes the last one.
// char	*ra(t_node **stk_a)
// {
// 	rotate(stk_a, false);
// 	// write(1, "ra\n", 3);
// 	printf("ra\n");
// 	return("ra\n");
// }

// rb (rotate b): Shift up all elements of stack b by 1. 
// The first element becomes the last one.
// char	*rb(t_node **stk_b)
// {
// 	rotate(stk_b, false);
// 	// write(1, "rb\n", 3);
// 	printf("rb\n");
// 	return("rb\n");
// }

// rr : ra and rb at the same time.
// char	*rr(t_node **stk_a, t_node **stk_b)
// {
// 	ra(stk_a);
// 	rb(stk_b);
// 	// write(1, "rr\n", 3);
// 	printf("rr\n");
// 	return("rr\n");
// }

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// char	*rra(t_node **stk_a)
// {
// 	rotate(stk_a, true);
// 	// write(1, "rra\n", 4);
// 	printf("rra\n");
// 	return("rra\n");
// }

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one. 
// char	*rrb(t_node **stk_b)
// {
// 	rotate(stk_b, true);
// 	// write(1, "rrb\n", 4);
// 	printf("rrb\n");
// 	return("rrb\n");
// }

// rrr : rra and rrb at the same time.
// char	*rrr(t_node **stk_a, t_node **stk_b)
// {
// 	rra(stk_a);
// 	rrb(stk_b);
// 	// write(1, "rrr\n", 4);
// 	printf("rrr\n");
// 	return("rrr\n");
// }
