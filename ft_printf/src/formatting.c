/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formatting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/22 12:39:14 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_arg_formatter.h"
#include "ft_printf_cust_data_types.h"
#include "ft_printf_cust_consts.h"
#include "ft_printf_puts.h"

size_t	add_width(size_t n)
{
	size_t	i;
	size_t	printed_char_count;

	i = 0;
	printed_char_count = 0;
	while (i < n)
	{
		printed_char_count += ft_put_char(CHAR_SPACE);
		i++;
	}
	return (printed_char_count);
}

size_t	add_precision(size_t n)
{
	size_t	i;
	size_t	printed_char_count;

	i = 0;
	printed_char_count = 0;
	while (i < n)
	{
		printed_char_count += ft_put_char(CHAR_ZERO);
		i++;
	}
	return (printed_char_count);
}

size_t	add_prefix(t_fmt *fmt, long long n)
{
	size_t	printed_char_count;	

	printed_char_count = 0;
	if (fmt->flags.space && n >= 0)
		printed_char_count += ft_put_char(CHAR_SPACE);
	else if (n < 0 && fmt->specifier != 'p')
		printed_char_count += ft_put_char(CHAR_MINUS);
	else if (fmt->flags.plus && n >= 0)
		printed_char_count += ft_put_char(CHAR_PLUS);
	else if (fmt->flags.hash && n != 0 && fmt->specifier == 'x')
		printed_char_count += ft_put_str(HEX_PREFIX_LOWER, 2);
	else if (fmt->flags.hash && n != 0 && fmt->specifier == 'X')
		printed_char_count += ft_put_str(HEX_PREFIX_UPPER, 2);
	else if (fmt->specifier == 'p')
		printed_char_count += ft_put_str(HEX_PREFIX_LOWER, 2);
	return (printed_char_count);
}
