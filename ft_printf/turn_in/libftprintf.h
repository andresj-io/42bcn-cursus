/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 10:55:58 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef enum e_pf_formats
{
	leftjustify,
	forcesigns,
	nosignspace,
	hex_precessed0,
	padzeros,
	unsigned_i,
	width,
	precision,
}	t_pf_formats;

typedef enum e_pf_flags
{
	character,
	string,
	pointer,
	decimal,
	integer,
	unsigned_i,
	hex_lower,
	hex_upper,
	percent,
}	t_pf_flags;

typedef struct s_print
{
	t_pf_formats	format;
	const char		*start;
	int				len;
	t_pf_flags		*flags;
	void			*value;
	int				width;
	int				precision;
}	t_print;

#endif