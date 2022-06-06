/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/13 21:13:24 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/06 15:30:03 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	parse_input(int argc, char *argv[], t_stacks *stks)
{
	long int	parsed_val;
	size_t		i;
	char		*curr_arg;
	t_node		*new_node;

	if (argc < 2)
		error_handling(stks, SILENT);
	i = 1;
	while (i < (size_t) argc)
	{
		curr_arg = argv[i];
		if (*curr_arg == '\0' || curr_arg[ft_strlen(curr_arg) - 1] == ' ')
			error_handling(stks, VERBOSE);
		while (*curr_arg)
		{
			parsed_val = ft_atoi_modded(&curr_arg, stks);
			new_node = create_node(parsed_val);
			if (new_node == NULL)
				error_handling(stks, VERBOSE);
			append_list(&stks->a.list, new_node);
			curr_arg += (*curr_arg == ' ');
		}
		i++;
	}
	set_stack_size(stks);
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
			error_handling(stks, VERBOSE);
		node = node->next;
	}
}
