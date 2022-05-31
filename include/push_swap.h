/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/31 23:58:33 by pmolnar       ########   odam.nl         */
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

// fastest_sorting_path.c
t_stacks	*duplicate_stks(t_stack *stk_a, t_stack *stk_b);
size_t		get_false_node_position(t_node *stk, int lookup);

// main.c
void		init_stacks(t_stacks *stks);

// sorting_algo.c
void		get_fastest_sorting_combo(t_stack *stk_a, t_stack *stk_b);
t_node		*get_matching_node(t_stack *stk, t_node *node);

// check_sorting.c
bool		is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// parse.c
void			parse_input(int argc, char *argv[], t_stacks *stk);
void			validate_data(t_stacks *stks);

// error.c
void			throw_error(t_stacks *stk, bool verbose);

// free_nodes.c
void			free_nodes(t_stacks *stks);

t_node			*get_extreme_val(t_node *stk, int extreme_type);

void			sort_stack(t_stacks *stks, size_t stk_size);

// index_list.c
void			index_list(t_stacks *stks);

// util.c
void			print_stacks(t_stacks *stk);
void			print_stacks_2(t_stack *stk_1, t_stack *stk_2);

// sorting_algo_util.c
t_node			*get_extreme_val(t_node *stk, int extreme_type);
unsigned int	get_min_move_count(t_node *node, t_stack *stk);
unsigned int	get_node_position(t_node *stk, t_node *node);
void			move_node_to_top(t_stack **stk, t_node *node, bool verbose);

// stack_preparation.c
void			separate_stacks(t_stacks *stks);

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