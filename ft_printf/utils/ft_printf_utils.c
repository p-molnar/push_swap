/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 16:43:18 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_arg_formatter.h"
#include "../libft/libft.h"
#include <stdarg.h>

int	index_of(const char str[], char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_max(size_t arg_count, ...)
{
	size_t	i;
	va_list	args;
	int		arg;
	int		max;

	i = 0;
	va_start(args, arg_count);
	max = va_arg(args, int);
	while (i < (arg_count - 1))
	{
		arg = va_arg(args, int);
		if (arg > max)
			max = arg;
		i++;
	}	
	va_end(args);
	return (max);
}

size_t	get_num_len(long long n)
{
	size_t	len;

	len = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_strupr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

char	*convert_dec_to_hex(unsigned long n)
{
	size_t			pos;
	char			*char_set;
	static char		converted_num[16 + 1];
	size_t			remainder;

	pos = 15;
	char_set = "0123456789abcdef";
	if (n == 0)
	{
		converted_num[0] = '0';
		return (converted_num);
	}
	while (n)
	{
		remainder = n % 16;
		converted_num[pos--] = char_set[remainder];
		n /= 16;
	}
	return (&converted_num[++pos]);
}
