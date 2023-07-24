/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/24 13:09:42 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
/*
typedef enum e_conversion
{
	pfe_character,
	pfe_string,
	pfe_integer,
	pfe_unsigned_int,
	pfe_hex_upper,
	pfe_hex_lower,
	pfe_pointer,
	pfe_percent,
}	t_conv_type;

typedef struct s_conv
{
	t_conv_type	type;
	char		*start;
	char		*end;
}	t_conversion;
*/

int			ft_printf(const char *format, ...);

/* No specifier */
t_status	pf_write_char(char c, ssize_t *count);
t_status	pf_write_str(char *str, ssize_t *count);
t_status	pf_write_null(ssize_t *count);

/* Specifiers */
t_status	pf_percent(ssize_t *count);
t_status	pf_char(va_list p_args, ssize_t *count);
t_status	pf_str(va_list p_args, ssize_t *count);
t_status	pf_int(va_list p_args, ssize_t *count);
t_status	pf_unsigned(va_list p_args, ssize_t *count);
t_status	pf_hex_lower(va_list p_args, ssize_t *count);
t_status	pf_hex_upper(va_list p_args, ssize_t *count);
t_status	pf_pointer(va_list p_args, ssize_t *count);

/* Flags */
char		*pf_add_hex_identifier(char *str);
/* Auxiliar */

#endif