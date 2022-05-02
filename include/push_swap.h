/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/02 16:46:54 by pmolnar       ########   odam.nl         */
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
# include <sl_list_ops.h>
# include <ps_sorting_ops.h>

enum {
	DESCENDING = -1,
	ASCENDING = 1,
};

enum {
	MIN = -1,
	MAX = 1,
};

void	parse_input(int argc, char *argv[], t_stks *stk);
void	throw_error(void);

// check_sorting.c
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// algo.c
void	sort_1(t_node **stk_a, t_node **stk_b, size_t list_size);
void	sort_2(t_node **stk_a, t_node **stk_b, size_t list_size);
t_node	*get_extreme_val(t_node *stk, int extreme_type);
void	sort_by_radix(t_node **stk_a, t_node **stk_b, size_t stack_size);
void	merge_sort(t_node **stk_a, t_node **stk_b, size_t list_size);
void	sort_stack_of_size_3(t_stk **stk, size_t stk_size, int order);
void	sort_stack_of_size_5(t_stk **stk, size_t stk_size, int order);

// index_list.c
t_node	*get_available_node(t_node *stk, t_node **used_nodes, size_t size);
void	rebase_list(t_node *stk);
int		index_of(t_node *lookup_val, t_node **arr, size_t arr_size);

// process_instructions.c
void	collect_instructions(char *instruction, char *new_instruction);

// util.c
void	print_stacks(t_stks *stk);
bool	is_stack_separated(t_node *stk, size_t counter, int criteria);
void	exec_suitable_sorting(t_stks *stk);

#endif