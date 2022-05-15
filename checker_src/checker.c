/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/05/16 00:32:51 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ps_custom_data_types.h>
#include <ps_sorting_ops.h>
#include <get_next_line.h>
#include <ft_printf.h>

#define STDIN 0

static void	init_stacks(t_stacks *stks)
{
	stks->a.list = NULL;
	stks->a.name = 'a';
	stks->b.list = NULL;
	stks->b.name = 'b';
}

int	main(int argc, char *argv[])
{
	unsigned int	initial_stk_size;
	t_stacks		stks;
	t_stack			*stk_a;
	t_stack			*stk_b;
	char			*cmd;

	stk_a = &stks.a;
	stk_b = &stks.b;
	init_stacks(&stks);
	parse_input(argc, argv, &stks);
	validate_data(&stks);
	initial_stk_size = stk_a->size;
	cmd = get_next_line(STDIN);
	while (cmd)
	{
		ft_printf("%s", cmd);
		exec_sorting_command(cmd);
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
