/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 14:49:01 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *, ...);

t_status	write_char(char c, int *pos, ssize_t *count);
t_status	write_string(char *str, int *pos, ssize_t *count);
t_status	pf_char(const char *str, int *pos, va_list *p_args, ssize_t *count);
t_status	pf_str(const char *str, int *pos, va_list *p_args, ssize_t *count);
t_status	pf_int(const char *str, int *pos, va_list *p_args, ssize_t *count);
t_status	pf_unsigned(\
	const char *str, int *pos, va_list *p_args, ssize_t *count);
t_status	pf_hex(const char *str, int *pos, va_list *p_args, ssize_t *count);

#endif