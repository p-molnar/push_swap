/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_util.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/06 14:58:47 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/06 19:17:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	set_stack_size(t_stacks *stks)
{
	stks->a.size = get_list_size(stks->a.list);
	stks->b.size = get_list_size(stks->b.list);
}

long int	ft_atoi_modded(char **str, t_stacks *stks)
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
		error_handling(stks, VERBOSE);
	while (**str && ft_isdigit(**str))
	{
		num = 10 * num + (**str - '0');
		(*str)++;
	}
	if (**str != ' ' && **str != '\0')
		error_handling(stks, VERBOSE);
	return (num * sign);
}

bool	is_in_int_range(long val)
{
	return ((val >= INT_MIN && val <= INT_MAX));
}

bool	is_unique_val(t_node *node, t_node *stack)
{
	t_node	*lookup_node;

	lookup_node = search_node_val(stack, node->val);
	if (lookup_node == NULL)
		return (true);
	return (false);
}
