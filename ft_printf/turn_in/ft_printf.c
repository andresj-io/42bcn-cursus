/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 12:25:48 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *, ...);
static t_status	write_normal(const char *str, int *pos, ssize_t *count);
static t_status	write_percent(const char *str, int *pos, ssize_t *count);
static t_status	write_conversions(\
	const char *str, int *pos, va_list *p_args, ssize_t *count);
static t_status	write_char(char c, int *pos, ssize_t *count);

int	ft_printf(const char *str, ...)
{
	va_list	p_args;
	int		count;
	int		i;

	if (!str || !*str)
		return (err);
	i = 0;
	count = 0;
	va_start(p_args, str);
	while (*(str + i))
	{
		if ((*(str + i) == '%' && *(str + i + 1) == '%') && 
			(write_char('%', i, &count) == err))
				return (-1);
		else if ((*(str + i) == '%')
			&& write_conversions(str + i, &i, p_args, count) == err)
			return (-1);
		else if (write_normal(str + i, &i, &count) == err)
			return (-1);
		i++;
	}
	va_end(p_args);
	return (count);
}

static t_status	write_char(char c, int *pos, ssize_t *count)
{
	(*pos)++;
	if (ft_putchar_fd(c, STDOUT_FILENO) < 0)
		return (err);
	(*count)++;
	return (ok);
}

static t_status	write_normal(const char *str, int *pos, ssize_t *count)
{
	while (*(str + *pos) != '%' && *(str + *pos))
	{
		if (write_char((char) *(str + *pos), pos, count) == err)
			return (err);
	}
	return (ok);
}

static t_status	write_conversions(\
	const char *str, int *pos, va_list *p_args, ssize_t *count)
{	
	if (ft_strchr(str, 'c'))
		pf_char();
	else if (ft_strchr(str, 's'))
		pf_str();
	else if (ft_strchr(str, 'p'))
		pf_pointer();
	else if (ft_strchr(str, 'd'))
		pf_int();
	else if (ft_strchr(str, 'i'))
		pf_int();
	else if (ft_strchr(str, 'u'))
		pf_unsigned();
	else if (ft_strchr(str, 'x'))
		pf_hex();
	else if (ft_strchr(str, 'X'))
		pf_hex();
}
