/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:24:23 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/18 14:49:08 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_status	pf_int(const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	int		num;
	char	*numc;
	int		printed;

	num = va_arg(p_args, int);
	numc = ft_itoa(num);
	printed = ft_putstr_fd(numc, STDOUT_FILENO);
	if (printed < 0)
		return (err);
	else
	{
		*count += printed;
		return (ok);
	}
}

t_status	pf_unsigned(\
	const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	unsigned int	num;
	char			*numc;
	int				printed;

	num = va_arg(p_args, unsigned int);
	numc = ft_itoa(num);
	printed = ft_putstr_fd(numc, STDOUT_FILENO);
	if (printed < 0)
		return (err);
	else
	{
		*count += printed;
		return (ok);
	}
}

t_status	pf_hex(const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	
}
