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

// static int	ft_atoi(const char *str)
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

int	ft_atoi_ptr_shifter(char **str)
{
	int			num;
	int			sign;
	const int	coeff[2] = {+1, -1};

	num = 0;
	sign = 1;
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str && (**str == '-' || **str == '+'))
	{
		sign = coeff[**str == '-'];
		(*str)++;
	}
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	return (sign * num);
}

static void	parse_values(int argc, char *argv[], t_sllist *stk)
{
	size_t	i;
	int		val;
	t_list	*new_node;
	char	*curr_arg;

	i = 1;
	while (i < (size_t)argc)
	{
		curr_arg = argv[i];
		while (*curr_arg)
		{
			val = ft_atoi_ptr_shifter(&curr_arg);
			printf("val = %d, curr_arg: %d\n", val, *curr_arg);
			new_node = ft_lstnew(&val);
			ft_lstadd_back(&(stk->a), new_node);
		}
		i++;
	}
}
			
static bool	is_valid_cla_format(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	char	*curr_arg;
	bool	on_number;
	
	i = 1;
	on_number = false;
	while (i < (size_t)argc)
	{
		curr_arg = argv[i];
		j = 0;
		while (curr_arg[j])
		{
			if (j == 0 && (!ft_isdigit(curr_arg[j]) || curr_arg[ft_strlen(curr_arg) - 1] == ' '))
				return (false);
			if (ft_isdigit(curr_arg[j]))
				on_number = true;
			else if (on_number && curr_arg[j] == ' ')
				on_number = false;
			else
				return (false);	
			j++;
		}
		i++;
	}
	return (true);
}

void	parse_cla(int argc, char *argv[], t_sllist *stk)
{
	(void)stk;
	if (is_valid_cla_format(argc, argv))
	{
		printf("valid val\n");
		parse_values(argc, argv, stk);
	}
	else
		throw_error();
}