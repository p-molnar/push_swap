/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/03 22:48:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

// t_node	*get_extreme_val(t_node *stk, int extreme_type)
// {
// 	t_node	*extreme_val_node;
// 	int		coeff;

// 	coeff = extreme_type;
// 	extreme_val_node = stk;
// 	while (stk)
// 	{
// 		if (coeff * *stk->val > coeff * *extreme_val_node->val)
// 			extreme_val_node = stk;
// 		stk = stk->next;
// 	}
// 	return (extreme_val_node);
// }

// static int	get_node_position(t_node *stk, t_node *node)
// {
// 	size_t	i;

// 	i = 0;
// 	while (stk && stk != node)
// 	{
// 		i++;
// 		stk = stk->next;
// 	}
// 	return (i);
// }

// void	sort_1(t_node **stk_a, t_node **stk_b, size_t list_size)
// {
// 	t_node	*min;
// 	size_t	min_pos;
// 	size_t	size;
// 	bool	is_closer_to_top;


// 	while (*stk_a != NULL && !is_stack_sorted(*stk_a, list_size, ASCENDING))
// 	{
// 		min = get_extreme_val(*stk_a, MIN);
// 		min_pos = get_node_position(*stk_a, min);
// 		size = get_sllist_size(*stk_a);
// 		is_closer_to_top = min_pos <= ((size - 1) - min_pos);
// 		// printf("min_val: %d\n", *min->val);
// 		// printf("min_pos: %zu\n", min_pos);
// 		// printf("is_closer_to_top: %d\n", is_closer_to_top);
// 		// printf("is_stack_sorted: %d\n", is_stack_sorted(*stk_a, list_size));
// 		// print_stacks(*stk_a, *stk_b);
// 		while (*stk_a != min)
// 		{
// 			if (is_closer_to_top)
// 				ra(stk_a);
// 			else
// 				rra(stk_a);	
// 		}
// 		if (!is_stack_sorted(*stk_a, list_size, ASCENDING))
// 			pb(stk_a, stk_b);
// 	}
// 	while (*stk_b != NULL)
// 		pa(stk_a, stk_b);
// 	// print_stacks(*stk_a, *stk_b);
// }

// void	sort_2(t_node **stk_a, t_node **stk_b, size_t list_size)
// {
// 	t_node	*top;
// 	t_node	*scnd_top;
// 	t_node	*btm;
// 	size_t	size;

// 	top = *stk_a;
// 	scnd_top = top->next;
// 	btm = get_last_node(*stk_a);
// 	size = get_sllist_size(*stk_a);

// 	// print_stacks(*stk_a, *stk_b);
// 	while (!is_stack_sorted(*stk_a, list_size, ASCENDING))
// 	{
// 		while (*stk_a != NULL && !is_stack_sorted(*stk_a, size, ASCENDING))
// 		{
// 			if (get_sllist_size(*stk_a) >= 3)
// 			{
// 				top = *stk_a;
// 				scnd_top = top->next;
// 				btm = get_last_node(*stk_a);
// 				if (*top->val < *scnd_top->val && *top->val < *btm->val)
// 					pb(stk_a, stk_b);
// 				else if (*scnd_top->val < *top->val && *scnd_top->val < *btm->val)
// 					sa(stk_a);
// 				else if (*btm->val < *top->val && *btm->val < *scnd_top->val)
// 					rra(stk_a);
// 			}
// 			else if (get_sllist_size(*stk_a) == 2)
// 			{
// 				top = *stk_a;
// 				btm = get_last_node(*stk_a);
// 				if (*top->val < *btm->val)
// 					pb(stk_a, stk_b);
// 				else
// 					rra(stk_a);
// 			}
// 			else
// 				pb(stk_a, stk_b);
// 			size = get_sllist_size(*stk_a);
// 			// print_stacks(*stk_a, *stk_b);
// 		}
// 		size = get_sllist_size(*stk_b);
// 		while (*stk_b != NULL)
// 		{
// 			if (is_stack_sorted(*stk_b, size, DESCENDING))
// 				pa(stk_a, stk_b);
// 			if (get_sllist_size(*stk_b) >= 3)
// 			{
// 				top = *stk_b;
// 				scnd_top = top->next;
// 				btm = get_last_node(*stk_b);
// 				if (*top->val > *scnd_top->val && *top->val > *btm->val)
// 					pa(stk_a, stk_b);
// 				else if (*scnd_top->val > *top->val && *scnd_top->val > *btm->val)
// 					sb(stk_b);
// 				else if (*btm->val > *top->val && *btm->val > *scnd_top->val)
// 					rrb(stk_b);
// 			}
// 			else if (get_sllist_size(*stk_b) == 2)
// 			{
// 				top = *stk_b;
// 				btm = get_last_node(*stk_b);
// 				if (*top->val > *btm->val)
// 					pa(stk_a, stk_b);
// 				else
// 					rrb(stk_b);
// 			}
// 			else
// 				pa(stk_a, stk_b);
// 			size = get_sllist_size(*stk_b);
// 			// print_stacks(*stk_a, *stk_b);
// 		}
// 	}
// 	// print_stacks(*stk_a, *stk_b);
// }

// void	exec_suitable_rotation(t_node **stk_a, size_t bit_count)
// {
// 	long int	bit_mask;
// 	t_node		*second_node;
// 	t_node		*last_node;

// 	bit_mask = 0b1;
// 	second_node = (*stk_a)->next;
// 	last_node = get_last_node(*stk_a);
// 	if (second_node == NULL)
// 		second_node = last_node;
// 	if ((*second_node->val >> bit_count & bit_mask) == 0)
// 		ra(stk_a);
// 	else if ((*last_node->val >> bit_count & bit_mask) == 0)
// 		rra(stk_a);
// 	else
// 		ra(stk_a);
// }

// void	get_node_to_top(t_node *top_node, t_node **stk)
// {
// 	size_t	stk_size;
// 	size_t	top_node_index;

// 	top_node_index = get_node_position(top_node, *stk);
// 	stk_size = get_sllist_size(*stk);
// 	while (*stk != top_node)
// 	{
// 		if (top_node_index <= stk_size / 2)
// 			ra(stk);
// 		else
// 			rra(stk);
// 	}
// }

// void	sort_by_radix(t_node **stk_a, t_node **stk_b, size_t stack_size)
// {
// 	long int	bit_mask;
// 	size_t		bit_shift_counter;
// 	t_node		*top_node_ptr;

// 	bit_mask = 0b1;
// 	bit_shift_counter = 0;
// 	top_node_ptr = NULL;
// 	while (!is_stack_sorted(*stk_a, stack_size, ASCENDING))
// 	{
// 		while (!is_stack_sorted(*stk_a, stack_size, ASCENDING) && !is_stack_separated(*stk_a, bit_shift_counter, 1))
// 		{
// 			if ((*(*stk_a)->val >> bit_shift_counter & bit_mask) == 0)
// 				pb(stk_a, stk_b);
// 			else
// 			{
// 				if (top_node_ptr == NULL)
// 					top_node_ptr = *stk_a;
// 				exec_suitable_rotation(stk_a, bit_shift_counter);
// 			}
// 			// print_stacks(*stk_a, *stk_b);
// 		}
// 		if (!is_stack_sorted(*stk_a, stack_size, ASCENDING))
// 			get_node_to_top(top_node_ptr, stk_a);
// 		while (*stk_b && !is_stack_sorted(*stk_a, stack_size, ASCENDING))
// 			pa(stk_a, stk_b);
// 		bit_shift_counter++;
// 		top_node_ptr = NULL;
// 	}
// }

// void	merge_sort(t_node **stk_a, t_node **stk_b, size_t stack_size)
// {
// 	t_node	*node_top;
// 	t_node	*node_btm;
// 	t_node	*node_scnd_top;

// 	while (!is_stack_sorted(*stk_a, stack_size, ASCENDING))
// 	{
// 		while (*stk_a && !is_stack_sorted(*stk_a, stack_size, ASCENDING))
// 		{
// 			// print_stacks(*stk_a, *stk_b);
// 			node_top = *stk_a;
// 			node_scnd_top = node_top->next;
// 			node_btm = get_last_node(*stk_a);

// 			if (node_scnd_top == NULL)
// 				node_scnd_top = node_btm;

// 			if (*node_scnd_top->val < *node_top->val && *node_scnd_top->val < *node_btm->val)
// 				sa(stk_a);
// 			else if (*node_btm->val < *node_top->val && *node_btm->val < *node_top->val)
// 				rra(stk_a);
// 			pb(stk_a, stk_b);	
// 		}
// 		while (stk_b && *stk_b)
// 		{
// 			// print_stacks(*stk_a, *stk_b);
// 			node_top = *stk_b;
// 			node_scnd_top = node_top->next;
// 			node_btm = get_last_node(*stk_b);

// 			if (node_scnd_top == NULL)
// 				node_scnd_top = node_btm;

// 			// if (*node_top->val > *node_scnd_top->value || *node_top->val > *node_btm->val)
// 			if (*node_scnd_top->val > *node_top->val && *node_scnd_top->val > *node_btm->val)
// 				sb(stk_b);
// 			else if (*node_btm->val > *node_top->val && *node_btm->val > *node_top->val)
// 				rrb(stk_b);
// 			pa(stk_a, stk_b);	
// 		}
// 	}
// }

void	sort_stack_of_size_3(t_stk **stk, size_t stk_size, int order)
{
	t_node	*top;
	t_node	*mid;
	t_node	*btm;

	top = (*stk)->sllist;
	mid = top->next;
	if (mid == NULL)
		mid = top;
	btm	= mid->next;
	if (btm == NULL)
		btm = mid;
	while (!is_stack_sorted((*stk)->sllist, stk_size, order))
	{
		if (order * *top->val > order * *mid->val)
		{
			if (order * *top->val > order * *btm->val)
				rotate(stk, false);
			else if (order * *top->val < order * *btm->val)
				swap(stk);
		}
		else if (order * *top->val < order * *mid->val)
			rotate(stk, true);
		sort_stack_of_size_3(stk, stk_size, order);
	}
}

void	sort_stack_of_size_5(t_stk **stk_a, t_stk **stk_b, int stk_size)
{
	push(stk_a, stk_b);
	// print_stacks_2(*stk_a, *stk_b);
	push(stk_a, stk_b);
	// print_stacks_2(*stk_a, *stk_b);
	sort_stack_of_size_3(stk_a, (*stk_a)->size, ASCENDING);
	// print_stacks_2(*stk_a, *stk_b);
	sort_stack_of_size_3(stk_b, (*stk_b)->size, DESCENDING);
	// print_stacks_2(*stk_a, *stk_b);
	while (!is_stack_sorted((*stk_a)->sllist, stk_size, ASCENDING))
	{
		if ((*stk_b)->sllist != NULL && 
			(*(*stk_a)->sllist->val - *(*stk_b)->sllist->val) == 1)
			push(stk_b, stk_a);
		else
			rotate(stk_a, false);
		// print_stacks_2(*stk_a, *stk_b);
	}
}