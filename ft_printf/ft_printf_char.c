/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:02:18 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/24 10:11:24 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	pf_char(const char *str, va_list p_args, ssize_t *count)
{
	int	c;

	c = va_arg(p_args, int);
	if (pf_write_char((char) c, count) == err)
		return (err);
	str++;
	return (ok);
}

t_status	pf_str(const char *str, va_list p_args, ssize_t *count)
{
	char	*s1;

	s1 = va_arg(p_args, char *);
	if (pf_write_str(s1, count) == err)
		return (err);
	str++;
	return (ok);
}

t_status	pf_percent(char *str, ssize_t *count)
{
	if (pf_write_char('%', count) == err)
		return (err);
	if (*str == '%')
		str++;
	return (ok);
}