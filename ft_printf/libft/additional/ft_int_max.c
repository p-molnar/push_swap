/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_int_max.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 18:34:03 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/07 18:34:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_int_max(size_t arg_count, ...)
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
