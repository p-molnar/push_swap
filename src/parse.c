/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 15:43:57 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/01 13:08:51by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include <push_swap.h>

static int	ft_atoi_modded(char **str, t_stacks *stks)
{
	int			num;
	int			sign;
	const int	coeff[2] = {+1, -1};

	num = 0;
	sign = 1;
	if (**str && (**str == '-' || **str == '+'))
	{
		sign = coeff[**str == '-'];
		(*str)++;
	}
	if (!ft_isdigit(**str))
		throw_error(stks);
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	if (**str != ' ' && **str != '\0')
		throw_error(stks);
	return (num * sign);
}

void	parse_input(int argc, char *argv[], t_stacks *stks)
{
	int		val;
	size_t	i;
	char	*curr_arg;
	t_node	*new_node;

	if (argc < 2)
		throw_error(stks);
	i = 1;
	while (i < (size_t) argc)
	{
		curr_arg = argv[i];
		if (curr_arg[ft_strlen(curr_arg) - 1] == ' ')
			throw_error(stks);
		while (*curr_arg)
		{
			val = ft_atoi_modded(&curr_arg, stks);
			if (!sllist_search(stks->a.list, val))
			{
				new_node = create_node(val);
				append_list(&stks->a.list, new_node);
			}
			else
				throw_error(stks);
			curr_arg += (*curr_arg == ' ');
		}
		i++;
	}
}
