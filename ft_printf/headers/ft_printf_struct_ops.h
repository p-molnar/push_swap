/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_struct_ops.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 14:03:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/23 15:50:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_STRUCT_OPS_H
# define FT_PRINTF_STRUCT_OPS_H
# include "ft_printf_cust_data_types.h"

void	init_fmt_struct(t_fmt *fmt);
size_t	populate_flags(const char *str, t_fmt *fmt);
size_t	populate_num(const char *str, int *n);
size_t	populate_specifier(const char *str, t_fmt *fmt_specs);

#endif