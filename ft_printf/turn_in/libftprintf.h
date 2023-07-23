/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/23 04:58:03 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

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
	char				*start;
	char				*end;
}	t_conversion;

int	ft_printf(const char *format, ...);

/* No specifier */
t_status	pf_write_char(char c, ssize_t *count);
t_status	pf_write_str(char *str, ssize_t *count);
t_status	pf_write_null(ssize_t *count);

/* Specifiers */
t_status	pf_percent(char *str, ssize_t *count);
t_status	pf_char(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_str(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_int(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_unsigned(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_hex_lower(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_hex_upper(const char *str, va_list *p_args, ssize_t *count);
t_status	pf_pointer(const char *str, va_list *p_args, ssize_t *count)

/* Flags */
char	*pf_add_hex_identifier(char *str);
/* Auxiliar */

#endif