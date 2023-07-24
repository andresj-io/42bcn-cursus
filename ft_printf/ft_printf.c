/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/24 13:02:41 by ajacome-         ###   ########.fr       */
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
			if (write_conversions(str, args, &count) == err)
				return (-1);
		}
		else if (pf_write_char(*str, count) == err)
			return (-1);
	}
	va_end(args);
	return (count);
}
/*
static t_status	write_normal(const char *str, ssize_t *count)
{
	while (*str != '%' && *str)
	{
		if (pf_write_char((char) *str, count) == err)
			return (err);
		str++;
	}
	return (ok);
}
*/

static t_status	write_conversions(char spec, va_list arg, ssize_t *count)
{
	if ((spec == 'c') && pf_char(spec, arg, count) == err)
		return (err);
	else if ((spec == 's') && pf_str(spec, arg, count) == err)
		return (err);
	else if ((spec == 'p') && pf_pointer(spec, arg, count) == err)
		return (err);
	else if ((spec == 'i' || spec == 'd') && pf_int(spec, arg, count) == err)
		return (err);
	else if ((spec == 'u') && pf_unsigned(spec, arg, count) == err)
		return (err);
	else if ((spec == 'x') && pf_hex_lower(spec, arg, count) == err)
		return (err);
	else if ((spec == 'X') && pf_hex_upper(spec, arg, count) == err)
		return (err);
	else if (pf_percent(spec, count) == err)
		return (err);
	return (ok);
}

/*

static void	determine_conversion(\
	char *str, t_conversion conv, const char *cases);
static t_status	pf_conversions(\
	t_conversion conv, va_list args, ssize_t *count);


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

int	main(void)
{
	int	ret;

	ret = 0;
	ret = ft_printf("HOLA\n");
	return (0);
}

