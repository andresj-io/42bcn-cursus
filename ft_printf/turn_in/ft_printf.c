/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 13:08:53 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_status	write_normal(const char *str, int *pos, ssize_t *count);
static t_status	write_conversions(\
	const char *str, int *pos, va_list *p_args, ssize_t *count);

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

static t_status	write_normal(const char *str, int *pos, ssize_t *count)
{
	int	len;

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
		pf_char(str, pos, p_args, count);
	else if (ft_strchr(str, 's'))
		pf_str(str, pos, p_args, count);
	else if (ft_strchr(str, 'p'))
		pf_pointer(str, pos, p_args, count);
	else if (ft_strchr(str, 'd'))
		pf_int(str, pos, p_args, count);
	else if (ft_strchr(str, 'i'))
		pf_int(str, pos, p_args, count);
	else if (ft_strchr(str, 'u'))
		pf_unsigned(str, pos, p_args, count);
	else if (ft_strchr(str, 'x'))
		pf_hex(str, pos, p_args, count);
	else if (ft_strchr(str, 'X'))
		pf_hex(str, pos, p_args, count);
}
