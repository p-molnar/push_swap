/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/18 10:29:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 13:43:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <ps_data_types.h>

typedef struct s_item
{
	char	*cmd_name;
	void	(*fn)(t_stacks **);
}	t_item;

// push_ops.c 
void	pa(t_stacks **stks);
void	pb(t_stacks **stks);

// rotate_ops.c
void	ra(t_stacks **stks);
void	rb(t_stacks **stks);
void	rr(t_stacks **stks);

// rev_rotate_ops.c
void	rra(t_stacks **stks);
void	rra(t_stacks **stks);
void	rrb(t_stacks **stks);
void	rrr(t_stacks **stks);

// swap_ops.c
void	sa(t_stacks **stks);
void	sb(t_stacks **stks);
void	ss(t_stacks **stks);

// checker.c
void	exec_sorting_cmd(char *cmd, t_stacks **stks);
#endif