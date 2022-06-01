/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_parser.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 16:59:11 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/01/25 16:59:12 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSER_H
# define FT_PRINTF_PARSER_H
# include "ft_printf_cust_data_types.h"

size_t	parse_formatting(const char *format_str, t_fmt *fmt);

#endif