/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_formatting_utils.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 19:37:00 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_cust_data_types.h"
#include "ft_printf_cust_consts.h"
#include "ft_printf_utils.h"
#include "../libft/libft.h"

size_t	get_prefix_len(t_fmt *fmt, long long n)
{
	size_t	len;

	len = 0;
	len += fmt->flags.plus;
	len += fmt->flags.space;
	len += fmt->flags.hash * ft_strlen(HEX_PREFIX_LOWER);
	len += (n < 0);
	return (len);
}

size_t	calc_precision(t_fmt *fmt, long long n, t_print_fmt p_fmt)
{
	size_t	precision;

	precision = get_max(2, fmt->precision - p_fmt.arg_len, 0);
	if (fmt->flags.zero && fmt->precision == -1)
		precision = get_max(2, fmt->width - p_fmt.arg_len - (n < 0), 0);
	return (precision);
}

size_t	calc_width(t_fmt *fmt, long long n, t_print_fmt p_fmt)
{
	size_t	width;

	width = get_max(2, p_fmt.total_len - p_fmt.precision \
	- p_fmt.arg_len - get_prefix_len(fmt, n), 0);
	if ((fmt->flags.space || fmt->flags.plus) \
	&& (fmt->specifier == 'd' || fmt->specifier == 'i'))
		width = get_max(2, width - 1, 0);
	else if (n == 0 && fmt->precision != -1 && fmt->specifier != '%')
		width = get_max(2, fmt->width - fmt->precision, 0);
	else if (fmt->specifier == 'p')
		width = get_max(2, width - 2, 0);
	return (width);
}
