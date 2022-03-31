/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:43:57 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/31 20:17:32 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <stdbool.h>
#include <stdio.h>

#include <push_swap.h>

// static int	ft_atoi_moded(const char *str)
// {
// }

// static void	parse_values(int argc, char *argv[], t_stk * stk)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*curr_arg;

// 	i = 0;
// 	while (i < (size_t)argc)
// 	{
// 		j = 0;
// 		curr_arg = argv[i];
// 		while (*curr_arg)
// 		{	
			
// 		}
// 	}
// }

static bool	is_valid_cla_format(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	char	*curr_arg;
	
	i = 1;
	while (i < (size_t)argc)
	{
		curr_arg = argv[i];
		j = 0;
		while (curr_arg[j])
		{
			if (ft_isdigit(curr_arg[j]) == false)
				return (false);
			else if (curr_arg[j] == ' ' && !ft_isdigit(curr_arg[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	parse_cla(int argc, char *argv[], t_stk *stk)
{
	(void)stk;
	if (is_valid_cla_format(argc, argv))
	{
		// parse_values(argc, argv, stk);
	}
}