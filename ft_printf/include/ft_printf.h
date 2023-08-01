/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/31 18:18:40 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/include/libft.h"
# include <stdarg.h>

int			ft_printf(const char *format, ...);

/* No specifier */
t_status	pf_write_char(char c, ssize_t *count);
t_status	pf_write_str(char *str, ssize_t *count);

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