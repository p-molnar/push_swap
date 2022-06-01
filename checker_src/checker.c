/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 18:28:35 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 00:56:31 by pmolnar       ########   odam.nl         */
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
	const t_item	ht[HT_SIZE] = {{"sa", &sa}, {"sb", &sb}, {"ss", &ss},
	{"pa", &pa}, {"pb", &pb}, {"ra", &ra},
	{"rb", &rb}, {"rr", &rr}, {"rra", &rra},
	{"rrb", &rrb}, {"rrr", &rrr}};
	int					i;

	i = 0;
	while (i < HT_SIZE)
	{
		if (ft_strncmp(ht[i].cmd_name, cmd, ft_strlen(cmd)) == 0)
		{
			ht[i].fn(stks);
		}
		i++;
	}
}

void	print_stacks(t_stacks *stk)
{
	t_node	*stk_a;
	t_node	*stk_b;

	stk_a = stk->a.list;
	stk_b = stk->b.list;
	printf("-----------+-----------\n");
	printf("%5c%c%5c|%5c%c%5c\n", ' ', 'a', ' ', ' ', 'b', ' ');
	printf("-----------+-----------\n");
	while (stk_a|| stk_b)
	{
		if (stk_a)
		{
			printf("%6ld", stk_a->val);
			stk_a = stk_a->next;
		}
		else
			printf("%6c", ' ');
		printf("%6c", '|');
		if (stk_b)
		{
			printf("%6ld", stk_b->val);
			stk_b = stk_b->next;
		}	
		else
			printf("%6c", ' ');
		printf("\n");
	}
	printf("-----------+-----------\n");
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
	validate_input(&stks);
	initial_stk_size = stk_a->size;
	cmd = get_next_line(STDIN);
	while (cmd)
	{
		exec_sorting_cmd(cmd, &stks_ptr);
		free(cmd);
		cmd = get_next_line(STDIN);
	}
	print_stacks(&stks);
	if (is_stack_sorted(stk_a->list, initial_stk_size, ASCENDING))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_nodes(&stks);
	return (EXIT_SUCCESS);
}
