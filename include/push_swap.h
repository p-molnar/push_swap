/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/11 16:48:51 by pmolnar       ########   odam.nl         */
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

# define DESC -1
# define ASC 1 

void	parse_cla(int argc, char *argv[], t_node **stk);
void	throw_error(void);

// check_sorting.c
bool	is_stack_sorted(t_node *stk, size_t list_size, int sorting);

// algo.c
void	sort_1(t_node **stk_a, t_node **stk_b, size_t list_size);
void	sort_2(t_node **stk_a, t_node **stk_b, size_t list_size);

// main.c
void	print_stacks(t_node *stk_a, t_node *stk_b);

#endif