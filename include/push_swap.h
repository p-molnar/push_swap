/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 15:16:22 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ps_data_types.h>
# include <ps_stack_ops.h>
# include <ps_list_ops.h>
# include <ps_consts.h>

// check_sorting.c 
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// error.c
void	error_handling(t_stacks *stks, bool verbose);

// free_node.c
void	free_nodes(t_stacks *stks);

// input.c
void	parse_input(int argc, char *argv[], t_stacks *stks);
void	validate_input(t_stacks *stks);

// sorting_algo_util.c
t_node	*get_matching_node(t_node *node_to_match, t_stack *stk);
size_t	get_node_index(t_node *stk, t_node *node);
int		get_min_op_count(t_node *node, t_stack *stk);
void	move_node_to_top(t_stack **stk, t_node *node, bool verbose);
t_node	*get_extreme_val_node(t_node *stk, int extreme_type);

// sorting_algo.c
void	sort_stack(t_stacks *stks, size_t stk_size);

#endif