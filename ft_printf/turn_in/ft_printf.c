/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:29:57 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/17 15:24:50 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *, ...);
static parse_pf(const char*str, va_list p_args);


int	ft_printf(const char *str, ...)
{
	va_list	p_args;

	if (!str || *str == '\0')
		return (error1);
	va_start(p_args, str);
	parse_pf();
	va_end(p_args);
}

static parse_pf(const char*str, va_list p_args)
{
	while (*str)
	{
		if (*str == )
		{
			/* code */
		}
		
	}
	
}

typedef