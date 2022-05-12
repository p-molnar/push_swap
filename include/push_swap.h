/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/12 21:50:08 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

# include <libft.h>
# include <ps_custom_data_types.h>
# include <list_ops.h>
# include <ps_sorting_ops.h>

enum {
	DESCENDING = -1,
	ASCENDING = 1,
};

enum {
	MIN = -1,
	MAX = 1,
};

// sorting.c
void	sort_stacks(t_stacks *stks, int stk_size);

// parse.c
void	validate_data(t_stacks *stks);

void	parse_input(int argc, char *argv[], t_stacks *stk);
void	throw_error(t_stacks *stk, bool is_verbose);

// check_sorting.c
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// algo.c
t_node	*get_extreme_val(t_node *stk, int extreme_type);
void	sort_stack_of_size_3(t_stack **stk, size_t stk_size, int order);
void	retain_sort(t_stacks *stks, int stk_size);

// index_list.c
t_node	*get_available_node(t_node *stk, t_node **used_nodes, size_t size);
void	add_indexing(t_node *stk);
int		index_of(t_node *lookup_val, t_node **arr, size_t arr_size);


// util.c
void	print_stacks(t_stacks *stk);
void	print_stacks_2(t_stack *stk_1, t_stack *stk_2);
void	exec_suitable_sorting(t_stacks *stk);

// head.c

unsigned int	get_ordered_el_count(t_node *node, t_node *stk_top);
t_node			*find_longest_coherent_list(t_node *stk);
void			mark_nodes_to_be_pushed(t_node *start_node, t_node *stk_top);
void			prepare_stacks_for_retain_sorting(t_stacks *stks);

#endif