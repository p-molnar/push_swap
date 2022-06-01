/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_cust_data_types.h                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 16:59:08 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 16:59:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CUST_DATA_TYPES_H
# define FT_PRINTF_CUST_DATA_TYPES_H
# include <stddef.h>
# include <stdbool.h>

typedef struct s_print
{
	size_t		total_len;
	size_t		arg_len;
	size_t		width;
	size_t		precision;

}				t_print_fmt;

typedef struct s_flags
{
	bool	minus;
	bool	plus;
	bool	space;
	bool	hash;
	bool	zero;
}				t_flags;

typedef struct s_fmt
{
	t_flags	flags;
	int		width;
	int		precision;
	char	specifier;
}				t_fmt;

#endif