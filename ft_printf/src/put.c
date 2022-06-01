/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/21 13:56:20 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:47:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_puts.h"
#include <unistd.h>

size_t	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_put_str(char *s, size_t len)
{
	size_t	printed_char_count;	

	printed_char_count = 0;
	printed_char_count += write(1, s, len);
	return (printed_char_count);
}

size_t	ft_put_nbr(long long n)
{
	size_t	printed_char_count;

	printed_char_count = 0;
	if (n < 0)
		printed_char_count += ft_put_nbr(-n);
	else if (n == 0)
		printed_char_count += ft_put_char('0');
	else if (n < 10)
		printed_char_count += ft_put_char(n + '0');
	else
	{
		printed_char_count += ft_put_nbr(n / 10);
		printed_char_count += ft_put_nbr(n % 10);
	}
	return (printed_char_count);
}
