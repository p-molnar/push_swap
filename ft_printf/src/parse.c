/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/23 15:51:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"
#include "ft_printf_struct_ops.h"
#include <stdarg.h>

size_t	parse_formatting(const char *format_str, t_fmt *fmt)
{
	size_t	i;

	i = 0;
	i += populate_flags(&format_str[i], fmt);
	i += populate_num(&format_str[i], &fmt->width);
	if (format_str[i] == '.')
	{
		fmt->precision = 0;
		i++;
	}
	i += populate_num(&format_str[i], &fmt->precision);
	i += populate_specifier(&format_str[i], fmt);
	return (i);
}
