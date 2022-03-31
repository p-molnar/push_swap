/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/31 20:11:56 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <push_swap.h>
#include <ps_custom_data_types.h>

int	main(int argc, char *argv[])
{
	t_stk	stk;
	if (argc < 2)
		return (EXIT_FAILURE);
	parse_cla(argc, argv, &stk);
	return (EXIT_SUCCESS);
}