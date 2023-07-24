/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/24 14:12:07 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_status	write_normal(const char *str, ssize_t *count);
static t_status	write_conversions(char spec, va_list arg, ssize_t *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	ssize_t	count;

	va_start(args, str);
	count = 0;
	if (!str || !*str)
		return (-1);
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

int	main(void)
{
	int	ret;

	ret = 0;
	ret = ft_printf("HOLA\n");
	ret = ft_printf(" NULL %s NULL ", NULL);
	ret = ft_printf(" %p %p ", 0, 0);
	ret = ft_printf("\n");
	ret = ft_printf(" %u %u %u %u %u %u %u",\
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ret = ft_printf(" %x ", 0);
	return (0);
}
