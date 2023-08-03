/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/02 09:32:34 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static t_status	write_conversions(char spec, va_list arg, ssize_t *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	ssize_t	count;

	va_start(args, str);
	count = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str == '%')
		{
			if (write_conversions(*(++str), args, &count) == err)
				return (-1);
		}
		else if (pf_write_char(*str, &count) == err)
			return (-1);
		str++;
	}
	va_end(args);
	return (count);
}

static t_status	write_conversions(char spec, va_list arg, ssize_t *count)
{
	if ((spec == 'c') && pf_char(arg, count) == err)
		return (err);
	else if ((spec == 's') && pf_str(arg, count) == err)
		return (err);
	else if ((spec == 'p') && pf_pointer(arg, count) == err)
		return (err);
	else if ((spec == 'i' || spec == 'd') && pf_int(arg, count) == err)
		return (err);
	else if ((spec == 'u') && pf_unsigned(arg, count) == err)
		return (err);
	else if ((spec == 'x') && pf_hex_lower(arg, count) == err)
		return (err);
	else if ((spec == 'X') && pf_hex_upper(arg, count) == err)
		return (err);
	else if ((spec == '%') && pf_percent(count) == err)
		return (err);
	return (ok);
}
