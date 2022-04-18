/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 13:46:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/04/18 17:22:49 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*buf;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = ft_strlen(s2);
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	buf = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!buf)
		exit(1);
	if (s1 !=NULL)
		ft_memcpy(buf, s1, s1_len);
	ft_memcpy(buf + s1_len, s2, s2_len);
	return (buf);
}

void	collect_instructions(char *all_instruction, char *new_instruction)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin_mod(all_instruction, new_instruction);
	if (all_instruction == NULL)
		exit(1);
}

void	cancel_out_redundant_ops(char *ops)
{
	(void) ops;
}