/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/23 04:55:15 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_status	write_normal(const char *str, ssize_t *count);
static t_status	write_conversions(char *str, va_list *arg, ssize_t *count);
static t_status	execute_conversion(char *str, va_list *args, ssize_t *count);

static void	determine_conversion(\
	char *str, t_conversion conv, const char *cases);
static t_status	pf_conversions(\
	t_conversion conv, va_list *args, ssize_t *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int			count;
	char		*pstr;

	count = 0;
	va_start(args, pstr);
	if (!pstr || !*pstr)
		return (err);
	while (*pstr)
	{
		if (*pstr == '%')
		{
			if (write_conversions(pstr, args, count) == err)
				return (-1);
		}
		else if (write_normal(pstr, &count) == err)
			return (-1);
	}
	va_end(args);
	return (count);
}

static t_status	write_normal(const char *str, ssize_t *count)
{
	int	len;

	while (*str != '%' && *str)
	{
		if (pf_write_char((char) *str, count) == err)
			return (err);
		str++;
	}
	return (ok);
}

static t_status	write_conversions(char *str, va_list *arg, ssize_t *count)
{	
	str++;
	if ((*str == 'c') && pf_char(str, arg, count) == err)
		return (err);
	else if ((*str == 's') && pf_str(str, arg, count) == err)
		return (err);
	else if ((*str == 'p') && pf_pointer(str, arg, count) == err)
		return (err);
	else if ((*str == 'i' || *cases == 'd') && pf_int(str, arg, count) == err)
		return (err);
	else if ((*str == 'u') && pf_unsigned(str, arg, count) == err)
		return (err);
	else if ((*str == 'x') && pf_hex_lower(str, arg, count) == err)
		return (err);
	else if ((*str == 'X') && pf_hex_upper(str, arg, count) == err)
		return (err);
	else if (pf_percent(str, count) == err)
		return (err);
	return (ok);
}
/*
static t_status	write_conversions(char *str, va_list *arg, ssize_t *count)
{	
	t_conversion	conv;

	str++;
	determine_conversion(str, conv, "cspdiuxX");
	if (conv.end)
	{
		conv.start = str;
		if (pf_conversions(conv, args, count) == err)
			return (err);
	}
	else if (conv.type = pfe_percent && pf_percent(str, count) == err)
		return (err);
	return (ok);
}

static t_status	execute_conversion(char *str, va_list *args, ssize_t *count)
{
	if (*str == 'c')
		conv.type = pfe_character;
	else if (*str == 's')
		conv.type = pfe_string;
	else if (*str == 'p')
		conv.type = pfe_pointer;
	else if (*str == 'i' || *cases == 'd')
		conv.type = pfe_integer;
	else if (*str == 'u')
		conv.type = pfe_unsigned_int;
	else if (*str == 'x')
		conv.type = pfe_hex_lower;
	else if (*str == 'X')
		conv.type = pfe_hex_upper;
	return ;
}

static t_status	pf_conversions(t_conversion conv, va_list *args, ssize_t *count)
{
	
	if ((*str == 'c') && pf_char(str, arg, count) == err)
		return (err);
	else if ((*str == 's') && pf_str(str, arg, count) == err)
		return (err);
	else if ((*str == 'p') && pf_pointer(str, arg, count) == err)
		return (err);
	else if ((*str == 'i' || *cases == 'd') 
		&& pf_int(str, arg, count) == err)
		return (err);
	else if ((*str == 'u') && pf_unsigned(str, arg, count) == err)
		return (err);
	else if ((*str == 'x') && pf_hex_lower(str, arg, count) == err)
		return (err);
	else if ((*str == 'X') && pf_hex_upper(str, arg, count) == err)
		return (err);
	else if (pf_percent(str, count) == err)
		return (err);
}

static void	determine_conversion(\
	char *str, t_conversion conv, const char *cases)
{
	while (*cases)
	{
		conv.end = ft_strchr(str, *cases);
		if (found)
		{
			if (*cases == 'c')
				conv.type = pfe_character;
			else if (*cases == 's')
				conv.type = pfe_string;
			else if (*cases == 'p')
				conv.type = pfe_pointer;
			else if (*cases == 'i' || *cases == 'd')
				conv.type = pfe_integer;
			else if (*cases == 'u')
				conv.type = pfe_unsigned_int;
			else if (*cases == 'x')
				conv.type = pfe_hex_lower;
			else if (*cases == 'X')
				conv.type = pfe_hex_upper;
			return ;
		}
		cases++;
	}
	conv.type = pfe_percent;
}
*/
