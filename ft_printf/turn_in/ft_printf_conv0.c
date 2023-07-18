/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:02:18 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 13:11:42 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_status	write_char(char c, int *pos, ssize_t *count)
{
	if (ft_putchar_fd(c, STDOUT_FILENO) < 0)
		return (err);
	(*pos)++;
	(*count)++;
	return (ok);
}

t_status	pf_char(const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	int	c;

	c = va_arg(p_args, char);
	if (write_char((char) c, pos, count) == err)
		return (err);
	return (ok);
}

t_status	pf_str(const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	char	*s1;
	int		printed;

	s1 = va_arg(p_args, char *);
	printed = ft_putstr_fd(s1, STDOUT_FILENO);
	if (printed < 0)
		return (err);
	else
	{
		*count += printed;
		return (ok);
	}
}