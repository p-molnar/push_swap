/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/20 16:08:28 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

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
 
void	parse_cla(int argc, char *argv[], t_node **stk);
void	throw_error(void);

// check_sorting.c
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// algo.c
void	sort_1(t_node **stk_a, t_node **stk_b, size_t list_size);
void	sort_2(t_node **stk_a, t_node **stk_b, size_t list_size);
t_node	*get_extreme_val(t_node *stk, int extreme_type);
void	sort_by_radix(t_node **stk_a, t_node **stk_b, size_t stack_size);
void	merge_sort(t_node **stk_a, t_node **stk_b, size_t list_size);

// main.c
void	print_stacks(t_node *stk_a, t_node *stk_b);

// index_list.c
t_node	*get_available_node(t_node *stk, t_node **used_nodes, size_t size);
void	index_list(t_node *stk);
int		index_of(t_node *lookup_val, t_node **arr, size_t arr_size);

// process_instructions.c
void	collect_instructions(char *instruction, char *new_instruction);

#endif