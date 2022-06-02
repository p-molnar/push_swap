/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_consts.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:33:04 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/06/02 14:34:43 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_CONSTS_H
# define PS_CONSTS_H
# include <limits.h>

enum {
	DESCENDING = -1,
	ASCENDING = 1,
};

enum {
	MIN = -1,
	MAX = 1,
};

enum {
	VERBOSE = true,
	SILENT = false,
};

enum {
	EXIT = true,
	NO_EXIT = false,
};

enum {
	REVERSE = true,
	NO_REVERSE = false,
};

#endif