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
#include <limits.h>

#include <push_swap.h>

static int	ft_atoi_modded(char **str, t_stacks *stks)
{
	long int	num;
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
		throw_error(stks, true);
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	if (**str != ' ' && **str != '\0')
		throw_error(stks, true);
	return (num * sign);
}

void	parse_input(int argc, char *argv[], t_stacks *stks)
{
	long int	parsed_val;
	size_t		i;
	char		*curr_arg;
	t_node		*new_node;

	if (argc < 2)
		throw_error(stks, false);
	i = 1;
	while (i < (size_t) argc)
	{
		curr_arg = argv[i];
		if (curr_arg[ft_strlen(curr_arg) - 1] == ' ')
			throw_error(stks, true);
		while (*curr_arg)
		{
			parsed_val = ft_atoi_modded(&curr_arg, stks);
			new_node = create_node(parsed_val);
			append_list(&stks->a.list, new_node);
			curr_arg += (*curr_arg == ' ');
		}
		i++;
	}
}

void	validate_data(t_stacks *stks)
{
	t_node	*stk_ptr;

	stk_ptr = stks->a.list;
	while (stk_ptr)
	{
		if (stk_ptr->val < INT_MIN || stk_ptr->val > INT_MAX \
			|| search_val(stk_ptr->next, stk_ptr->val))
			throw_error(stks, true);
		stk_ptr = stk_ptr->next;
	}
}
