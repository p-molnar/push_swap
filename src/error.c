/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 16:01:23 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/31 20:13:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#define STDERR 2

void	throw_error(void)
{
	const char *error_msg = "error\n";
	write(STDERR, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}