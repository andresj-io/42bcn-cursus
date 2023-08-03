/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:24:23 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/02 09:32:38 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

t_status	pf_int(va_list p_args, ssize_t *count)
{
	int		num;
	char	*numc;

	num = va_arg(p_args, int);
	numc = ft_itoa(num);
	if (!numc)
		return (err);
	if (pf_write_str(numc, count) == err)
	{
		free(numc);
		return (err);
	}
	free(numc);
	return (ok);
}

t_status	pf_unsigned(va_list p_args, ssize_t *count)
{
	unsigned int	num;
	char			*numc;

	num = va_arg(p_args, unsigned int);
	numc = ft_utoa(num);
	if (!numc)
		return (err);
	if (pf_write_str(numc, count) == err)
	{
		free(numc);
		return (err);
	}
	free(numc);
	return (ok);
}
