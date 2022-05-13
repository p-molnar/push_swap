/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/14 00:42:13 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

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
// check_sorting.c
bool			is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// parse.c
void			parse_input(int argc, char *argv[], t_stacks *stk);
void			validate_data(t_stacks *stks);

// error.c
void			throw_error(t_stacks *stk, bool verbose);

// free_nodes.c
void			free_nodes(t_stacks *stk);

t_node			*get_extreme_val(t_node *stk, int extreme_type);

// algo.c
void			sort_stack_of_size_3(t_stack **stk, size_t stk_size, int order);
void			retain_sort(t_stacks *stks, int stk_size);

// index_list.c
void			add_indexing(t_stacks *stks);

// util.c
void			print_stacks(t_stacks *stk);
void			print_stacks_2(t_stack *stk_1, t_stack *stk_2);

// sorting_algo_util.c
t_node			*get_extreme_val(t_node *stk, int extreme_type);
unsigned int	get_min_move_count(t_node *node, t_stack *stk);
unsigned int	get_node_position(t_node *stk, t_node *node);
void			move_node_to_top(t_stack **stk_a, t_node *lookup);

// stack_preparation.c
void			prepare_stacks_for_sorting(t_stacks *stks);

// stack_preparation_util.c
bool			stk_has_marked_node(t_node *stk);
void			push_closest_marked_node(t_stacks *stks);
unsigned int	get_ordered_el_count(t_node *node, t_node *stk_top);

// stack_operation_util.c
void			do_rotation(t_stack **stk);
void			do_reverse_rotation(t_stack **stk);
void			update_stk_size(t_stack **stk_1, t_stack **stk_2);
t_node			*pop(t_node **stk);

#endif