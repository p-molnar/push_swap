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
#include <sl_list_ops.h>


static int	ft_atoi_modded(char **str)
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
		throw_error();
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	if (**str != ' ' && **str != '\0')
		throw_error();
	return (num * sign);
}

void	parse_values(int argc, char *argv[], t_node **stk)
{
	int		val;
	size_t	i;
	char	*curr_arg;
	t_node	*new_node;

	i = 1;
	while (i < (size_t)argc)
	{
		curr_arg = argv[i];
		if (curr_arg[ft_strlen(curr_arg) - 1] == ' ')
			throw_error();
		while (*curr_arg)
		{
			val = ft_atoi_modded(&curr_arg);
			// printf("val = %d, curr_arg_ptr: %d\n", val, *curr_arg);
			if (!sllist_search(*stk, val))
			{
				new_node = create_node(val);
				// printf("new_node_content: %d\n", *new_node->val);
				sllist_append(stk, new_node);
			}
			else
				throw_error();
			if (*curr_arg == ' ')
				curr_arg++;
		}
		i++;
	}
}

void	parse_cla(int argc, char *argv[], t_node **stk)
{
	parse_values(argc, argv, stk);
}