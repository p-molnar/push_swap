/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:50:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/01 11:10:48 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <ps_custom_data_types.h>

void	parse_cla(int argc, char *argv[], t_sllist * stk);
void	throw_error(void);

#endif