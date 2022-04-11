/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:29:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/11 18:16:12 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <push_swap.h>

static t_node	*get_min_val(t_node *stk)
{
	t_node	*min;

	min = stk;
	while (stk)
	{
		if (*stk->val < *min->val)
			min = stk;
		stk = stk->next;
	}
	return (min);
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


	while (*stk_a != NULL && !is_stack_sorted(*stk_a, list_size, ASC))
	{
		min = get_min_val(*stk_a);
		min_pos = get_node_position(*stk_a, min);
		size = get_sllist_size(*stk_a);
		is_closer_to_top = min_pos < ((size - 1) - min_pos);
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

	print_stacks(*stk_a, *stk_b);
	while (!is_stack_sorted(*stk_a, list_size, ASC))
	{
		while (*stk_a != NULL && !is_stack_sorted(*stk_a, size, ASC))
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
			if (is_stack_sorted(*stk_b, size, DESC))
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

