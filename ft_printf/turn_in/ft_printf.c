/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/17 15:56:47 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *, ...);
static int	parse_pf(const char*str, va_list p_args);


int	ft_printf(const char *str, ...)
{
	va_list	p_args;
	int		status;

	if (!str || *str == '\0')
		return (error1);
	va_start(p_args, str);
	status = parse_pf(str, p_args);
	va_end(p_args);
	if (status == error1)
		return (-1);
	else
		return (0);
}

static int	parse_pf(const char*str, va_list p_args)
{
	while (*str)
	{
		if (*str != '%')
		{
			
		}
		else
			if (ft_putchar_fd(*str, STDOUT_FILENO) < 0)
				return (error1);
	}
	return (ok);
}

typedef