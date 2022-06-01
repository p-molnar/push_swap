/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 21:13:24 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/01 11:10:54 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <push_swap.h>
#include <libft.h>

static long int	ft_atoi_modded(char **str, t_stacks *stks)
{
	const int	coeff[2] = {+1, -1};
	long		num;
	int			sign;

	num = 0;
	sign = 1;
	if (**str && (**str == '-' || **str == '+'))
	{
		sign = coeff[**str == '-'];
		(*str)++;
	}
	if (!ft_isdigit(**str))
		error(stks, VERBOSE);
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	if (**str != ' ' && **str != '\0')
		error(stks, VERBOSE);
	return (num * sign);
}

static bool	is_in_int_range(long val)
{
	return ((val >= INT_MIN && val <= INT_MAX));
}

static bool	is_unique_val(t_node *node, t_node *stack)
{
	t_node	*node_ptr;

	node_ptr = search_node_val(stack, node->val);
	if (node_ptr == NULL)
		return (true);
	return (false);
}

void	parse_input(int argc, char *argv[], t_stacks *stks)
{
	long int	parsed_val;
	size_t		i;
	char		*curr_arg;
	t_node		*new_node;

	if (argc < 2)
		error(stks, NO_VERBOSE);
	i = 1;
	while (i < (size_t) argc)
	{
		curr_arg = argv[i];
		if (curr_arg[ft_strlen(curr_arg) - 1] == ' ')
			error(stks, VERBOSE);
		while (*curr_arg)
		{
			parsed_val = ft_atoi_modded(&curr_arg, stks);
			new_node = create_node(parsed_val);
			append_list(&stks->a.list, new_node);
			curr_arg += (*curr_arg == ' ');
		}
		i++;
	}
	stks->a.size = get_list_size(stks->a.list);
	stks->b.size = get_list_size(stks->b.list);
}

void	validate_input(t_stacks *stks)
{
	t_node	*node;
	long	val;
	bool	unique_val;
	bool	val_in_int_range;

	node = stks->a.list;
	while (node != NULL)
	{
		val = node->val;
		unique_val = is_unique_val(node, node->next);
		val_in_int_range = is_in_int_range(val);
		if (unique_val == false || val_in_int_range == false)
			error(stks, VERBOSE);
		node = node->next;
	}
}
