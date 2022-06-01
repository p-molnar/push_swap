/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate_struct.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 14:03:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_struct_ops.h"
#include "ft_printf_cust_data_types.h"
#include "ft_printf_cust_consts.h"
#include "ft_printf_utils.h"
#include <stdbool.h>

void	init_fmt_struct(t_fmt *fmt)
{
	fmt->flags.minus = false;
	fmt->flags.plus = false;
	fmt->flags.space = false;
	fmt->flags.hash = false;
	fmt->flags.zero = false;
	fmt->width = -1;
	fmt->precision = -1;
	fmt->specifier = '\0';
}

size_t	populate_flags(const char *str, t_fmt *fmt)
{
	size_t	i;
	char	flag;

	i = 0;
	while (index_of(PRINTF_FLAGS, str[i]) >= 0)
	{
		flag = str[i];
		if (flag == '-')
			fmt->flags.minus = true;
		else if (flag == '+')
			fmt->flags.plus = true;
		else if (flag == '0')
			fmt->flags.zero = true;
		else if (flag == '#')
			fmt->flags.hash = true;
		else if (flag == ' ')
			fmt->flags.space = true;
		i++;
	}
	return (i);
}

size_t	populate_num(const char *str, int *n)
{
	size_t	num;
	size_t	num_len;

	if (!ft_isdigit(str[0]))
		return (0);
	num = ft_atoi(str);
	*n = num;
	num_len = get_num_len(num);
	return (num_len);
}

size_t	populate_specifier(const char *str, t_fmt *fmt_specs)
{
	char	specifier;

	specifier = str[0];
	if (index_of(PRINTF_SPECIFIERS, specifier) >= 0)
		(*fmt_specs).specifier = specifier;
	return (1);
}
