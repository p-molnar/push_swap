/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:24:29 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/26 13:00:41 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_struct_ops.h"
#include "ft_printf_arg_printer.h"
#include "ft_printf_cust_consts.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	size_t		index_offset;
	size_t		char_count;
	t_fmt		fmt;

	char_count = 0;
	i = 0;
	index_offset = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == CHAR_PERC)
		{
			init_fmt_struct(&fmt);
			index_offset = parse_formatting(&format[i + 1], &fmt);
			char_count += print_arg(&fmt, &args);
			i += index_offset;
		}
		else
			char_count += ft_printf("%c", format[i]);
		i++;
	}
	va_end(args);
	return (char_count);
}

size_t	print_arg(t_fmt *fmt, va_list *arg_list)
{
	size_t	char_count;

	char_count = 0;
	if (fmt->specifier == 'c')
		char_count += print_char(fmt, va_arg(*arg_list, int));
	else if (fmt->specifier == 's')
		char_count += print_str(fmt, va_arg(*arg_list, char *));
	else if (fmt->specifier == 'p')
		char_count += print_hex_num(fmt, va_arg(*arg_list, unsigned long));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		char_count += print_num(fmt, va_arg(*arg_list, int));
	else if (fmt->specifier == 'u')
		char_count += print_num(fmt, va_arg(*arg_list, unsigned int));
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		char_count += print_hex_num(fmt, va_arg(*arg_list, unsigned int));
	else if (fmt->specifier == '%')
		char_count += print_perc(fmt);
	return (char_count);
}
