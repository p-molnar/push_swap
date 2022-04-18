/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/18 17:43:37 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

t_node	*get_extreme_val(t_node *stk, int extreme_type)
{
	t_node	*extreme_val_node;
	int		coeff;

	coeff = extreme_type;
	extreme_val_node = stk;
	while (stk)
	{
		if (coeff * *stk->val > coeff * *extreme_val_node->val)
			extreme_val_node = stk;
		stk = stk->next;
	}
	return (extreme_val_node);
}

static int	get_node_position(t_node *stk, t_node *node)
{
	size_t	i;

	i = 0;
	while (stk && stk != node)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

void	sort_1(t_node **stk_a, t_node **stk_b, size_t list_size)
{
	t_node	*min;
	size_t	min_pos;
	size_t	size;
	bool	is_closer_to_top;


	while (*stk_a != NULL && !is_stack_sorted(*stk_a, list_size, ASCENDING))
	{
		min = get_extreme_val(*stk_a, MIN);
		min_pos = get_node_position(*stk_a, min);
		size = get_sllist_size(*stk_a);
		is_closer_to_top = min_pos <= ((size - 1) - min_pos);
		// printf("min_val: %d\n", *min->val);
		// printf("min_pos: %zu\n", min_pos);
		// printf("is_closer_to_top: %d\n", is_closer_to_top);
		// printf("is_stack_sorted: %d\n", is_stack_sorted(*stk_a, list_size));
		// print_stacks(*stk_a, *stk_b);
		while (*stk_a != min)
		{
			if (is_closer_to_top)
				ra(stk_a);
			else
				rra(stk_a);	
		}
		if (!is_stack_sorted(*stk_a, list_size, ASCENDING))
			pb(stk_a, stk_b);
	}
	while (*stk_b != NULL)
		pa(stk_a, stk_b);
	// print_stacks(*stk_a, *stk_b);
}

void	sort_2(t_node **stk_a, t_node **stk_b, size_t list_size)
{
	t_node	*top;
	t_node	*scnd_top;
	t_node	*btm;
	size_t	size;

	top = *stk_a;
	scnd_top = top->next;
	btm = get_last_node(*stk_a);
	size = get_sllist_size(*stk_a);

	// print_stacks(*stk_a, *stk_b);
	while (!is_stack_sorted(*stk_a, list_size, ASCENDING))
	{
		while (*stk_a != NULL && !is_stack_sorted(*stk_a, size, ASCENDING))
		{
			if (get_sllist_size(*stk_a) >= 3)
			{
				top = *stk_a;
				scnd_top = top->next;
				btm = get_last_node(*stk_a);
				if (*top->val < *scnd_top->val && *top->val < *btm->val)
					pb(stk_a, stk_b);
				else if (*scnd_top->val < *top->val && *scnd_top->val < *btm->val)
					sa(stk_a);
				else if (*btm->val < *top->val && *btm->val < *scnd_top->val)
					rra(stk_a);
			}
			else if (get_sllist_size(*stk_a) == 2)
			{
				top = *stk_a;
				btm = get_last_node(*stk_a);
				if (*top->val < *btm->val)
					pb(stk_a, stk_b);
				else
					rra(stk_a);
			}
			else
				pb(stk_a, stk_b);
			size = get_sllist_size(*stk_a);
			// print_stacks(*stk_a, *stk_b);
		}
		size = get_sllist_size(*stk_b);
		while (*stk_b != NULL)
		{
			if (is_stack_sorted(*stk_b, size, DESCENDING))
				pa(stk_a, stk_b);
			if (get_sllist_size(*stk_b) >= 3)
			{
				top = *stk_b;
				scnd_top = top->next;
				btm = get_last_node(*stk_b);
				if (*top->val > *scnd_top->val && *top->val > *btm->val)
					pa(stk_a, stk_b);
				else if (*scnd_top->val > *top->val && *scnd_top->val > *btm->val)
					sb(stk_b);
				else if (*btm->val > *top->val && *btm->val > *scnd_top->val)
					rrb(stk_b);
			}
			else if (get_sllist_size(*stk_b) == 2)
			{
				top = *stk_b;
				btm = get_last_node(*stk_b);
				if (*top->val > *btm->val)
					pa(stk_a, stk_b);
				else
					rrb(stk_b);
			}
			else
				pa(stk_a, stk_b);
			size = get_sllist_size(*stk_b);
			// print_stacks(*stk_a, *stk_b);
		}
	}
	// print_stacks(*stk_a, *stk_b);
}

bool	is_stack_separated(t_node *stk, size_t counter , int criteria)
{
	long int	bit_mask;

	bit_mask = 0b1;
	while (stk)
	{
		if ((*(stk->val) >> counter & bit_mask) != criteria)
			return (false);
		stk = stk->next;
	}
	return (true);
}

// sort stack by radix
void	sort_stack(t_node **stk_a, t_node **stk_b, size_t stack_size)
{
	long int	bit_mask;
	t_node			*tmp;
	size_t			counter;
	size_t			ra_count;

	bit_mask = 0b1;
	tmp = *stk_a;
	counter = 0;
	while (!is_stack_sorted(*stk_a, stack_size, ASCENDING))
	{
		ra_count = 0;
		// printf("check %zu bit from left:\n", counter + 1);
		while (!is_stack_sorted(*stk_a, stack_size, ASCENDING) && !is_stack_separated(*stk_a, counter, 1))
		{
			if ((*(*stk_a)->val >> counter & bit_mask) == 0)
				pb(stk_a, stk_b);
			else
			{
				ra_count++;
				ra(stk_a);
			}
			// print_stacks(*stk_a, *stk_b);
		}
		while (!is_stack_sorted(*stk_a, stack_size, ASCENDING) && ra_count--)
			rra(stk_a);
		while (!is_stack_sorted(*stk_a, stack_size, ASCENDING) && *stk_b)
			pa(stk_a, stk_b);
		counter++;
		// bit_mask = bit_mask << 1;
	}
}

void	merge_sort(t_node **stk_a, t_node **stk_b, size_t stack_size)
{
	t_node	*node_top;
	t_node	*node_btm;
	t_node	*node_scnd_top;

	while (!is_stack_sorted(*stk_a, stack_size, ASCENDING))
	{
		while (*stk_a && !is_stack_sorted(*stk_a, stack_size, ASCENDING))
		{
			print_stacks(*stk_a, *stk_b);
			node_top = *stk_a;
			node_scnd_top = node_top->next;
			node_btm = get_last_node(*stk_a);

			if (node_scnd_top == NULL)
				node_scnd_top = node_btm;

			if (*node_scnd_top->val < *node_top->val && *node_scnd_top->val < *node_btm->val)
				sa(stk_a);
			else if (*node_btm->val < *node_top->val && *node_btm->val < *node_top->val)
				rra(stk_a);
			pb(stk_a, stk_b);	
		}
		while (stk_b && *stk_b)
		{
			print_stacks(*stk_a, *stk_b);
			node_top = *stk_b;
			node_scnd_top = node_top->next;
			node_btm = get_last_node(*stk_b);

			if (node_scnd_top == NULL)
				node_scnd_top = node_btm;

			// if (*node_top->val > *node_scnd_top->value || *node_top->val > *node_btm->val)
			if (*node_scnd_top->val > *node_top->val && *node_scnd_top->val > *node_btm->val)
				sb(stk_b);
			else if (*node_btm->val > *node_top->val && *node_btm->val > *node_top->val)
				rrb(stk_b);
			pa(stk_a, stk_b);	
		}
	}
}