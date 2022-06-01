/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 17:01:52 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 17:01:53 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H
# include <stddef.h>

int		index_of(const char str[], char c);
int		get_max(size_t arg_count, ...);
char	*convert_dec_to_hex(unsigned long n);
char	*ft_strupr(char *s);
size_t	get_num_len(long long n);

#endif