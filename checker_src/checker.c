/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/19 13:50:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <get_next_line.h>
#include <libft.h>
#include <ft_printf.h>
#include <checker.h>

#define STDIN 0
#define HT_SIZE 11

void	exec_sorting_cmd(char *cmd, t_stacks **stks)
{
	static const t_item	ht[HT_SIZE] = {{"sa", &sa}, {"sb", &sb}, {"ss", &ss},
	{"pa", &pa}, {"pb", &pb}, {"ra", &ra},
	{"rb", &rb}, {"rr", &rr}, {"rra", &rra},
	{"rrb", &rrb}, {"rrr", &rrr}};
	int					i;

	i = 0;
	while (i < HT_SIZE)
	{
		if (ft_strncmp(ht[i].cmd_name, cmd, ft_strlen(cmd) - 1) == 0)
		{
			ht[i].fn(stks);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	initial_stk_size;
	t_stacks		stks;
	t_stacks		*stks_ptr;
	t_stack			*stk_a;
	char			*cmd;

	stks_ptr = &stks;
	stk_a = &stks.a;
	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_data(&stks);
	initial_stk_size = stk_a->size;
	cmd = get_next_line(STDIN);
	while (cmd)
	{
		exec_sorting_cmd(cmd, &stks_ptr);
		free(cmd);
		cmd = get_next_line(STDIN);
	}
	if (is_stack_sorted(stk_a->list, initial_stk_size, ASCENDING))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_nodes(&stks);
	return (EXIT_SUCCESS);
}
