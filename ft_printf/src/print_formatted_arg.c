/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_formatted_arg.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 16:43:46 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_cust_data_types.h"
#include "ft_printf_cust_consts.h"
#include "ft_printf_arg_formatter.h"
#include "ft_printf_utils.h"
#include "ft_printf_puts.h"

#include <stdio.h>

size_t	print_char(t_fmt *fmt, int c)
{
	size_t		printed_char_count;
	t_print_fmt	print_fmt;

	print_fmt.arg_len = 1;
	print_fmt.total_len = get_max(2, fmt->width, print_fmt.arg_len);
	print_fmt.width = print_fmt.total_len - print_fmt.arg_len;
	printed_char_count = 0;
	if (!fmt->flags.minus)
		printed_char_count += add_width(print_fmt.width);
	printed_char_count += ft_put_char(c);
	if (fmt->flags.minus)
		printed_char_count += add_width(print_fmt.width);
	return (printed_char_count);
}

size_t	print_str(t_fmt *fmt, char *str)
{
	size_t		printed_char_count;
	t_print_fmt	print_fmt;

	printed_char_count = 0;
	if (!str)
		return (print_str(fmt, "(null)"));
	print_fmt.arg_len = ft_strlen(str);
	if (fmt->specifier == 's' && fmt->precision != -1 \
		&& fmt->precision < (int) print_fmt.arg_len)
		print_fmt.arg_len = fmt->precision;
	print_fmt.total_len = get_max(2, fmt->width, print_fmt.arg_len);
	print_fmt.width = get_max(2, print_fmt.total_len - print_fmt.arg_len, 0);
	if (!fmt->flags.minus)
		printed_char_count += add_width(print_fmt.width);
	printed_char_count += add_prefix(fmt, 0);
	printed_char_count += ft_put_str(str, print_fmt.arg_len);
	if (fmt->flags.minus)
		printed_char_count += add_width(print_fmt.width);
	return (printed_char_count);
}

size_t	print_num(t_fmt *fmt, long long n)
{
	size_t		printed_char_count;
	t_print_fmt	p_fmt;

	printed_char_count = 0;
	p_fmt.arg_len = get_num_len(n);
	p_fmt.total_len = get_max(3, fmt->width, fmt->precision, p_fmt.arg_len);
	p_fmt.precision = calc_precision(fmt, n, p_fmt);
	p_fmt.width = calc_width(fmt, n, p_fmt);
	if (!fmt->flags.minus)
		printed_char_count += add_width(p_fmt.width);
	printed_char_count += add_prefix(fmt, n);
	printed_char_count += add_precision(p_fmt.precision);
	if (n != 0 || fmt->precision != 0)
		printed_char_count += ft_put_nbr(n);
	if (fmt->flags.minus)
		printed_char_count += add_width(p_fmt.width);
	return (printed_char_count);
}

size_t	print_hex_num(t_fmt *fmt, long long n)
{
	size_t		printed_char_count;	
	t_print_fmt	p_fmt;
	char		*converted_num;

	printed_char_count = 0;
	converted_num = convert_dec_to_hex(n);
	if (fmt->specifier == 'X')
		converted_num = ft_strupr(converted_num);
	p_fmt.arg_len = ft_strlen(converted_num);
	p_fmt.total_len = get_max(3, fmt->width, fmt->precision, p_fmt.arg_len);
	p_fmt.precision = calc_precision(fmt, n, p_fmt);
	p_fmt.width = calc_width(fmt, n, p_fmt);
	if (!fmt->flags.minus)
		printed_char_count += add_width(p_fmt.width);
	printed_char_count += add_prefix(fmt, n);
	printed_char_count += add_precision(p_fmt.precision);
	if (n != 0 || fmt->precision != 0)
		printed_char_count += ft_put_str(converted_num, p_fmt.arg_len);
	if (fmt->flags.minus)
		printed_char_count += add_width(p_fmt.width);
	return (printed_char_count);
}

size_t	print_perc(t_fmt *fmt)
{
	size_t		printed_char_count;	
	t_print_fmt	p_fmt;

	printed_char_count = 0;
	fmt->precision = 0;
	p_fmt.precision = 0;
	p_fmt.arg_len = 1;
	p_fmt.total_len = get_max(3, fmt->width, fmt->precision, p_fmt.arg_len);
	p_fmt.width = calc_width(fmt, 0, p_fmt);
	if (!fmt->flags.minus && !fmt->flags.zero)
		printed_char_count += add_width(p_fmt.width);
	if (!fmt->flags.minus && fmt->flags.zero)
		printed_char_count += add_precision(p_fmt.width);
	printed_char_count += ft_put_char(CHAR_PERC);
	if (fmt->flags.minus)
		printed_char_count += add_width(p_fmt.width);
	return (printed_char_count);
}
