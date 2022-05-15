/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 23:39:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/14 19:12:14 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../ft_printf/headers/ft_printf_cust_data_types.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	print_arg(t_fmt *fmt, va_list *arg_list);

#endif