/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 05:06:07 by andresj           #+#    #+#             */
/*   Updated: 2023/07/24 13:42:19 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	pf_hex_lower(va_list p_args, ssize_t *count)
{
	char			*numc;
	unsigned int	num;

	num = va_arg(p_args, unsigned int);
	numc = ft_utox(num);
	if (!numc)
		return (err);
	if (pf_write_str(numc, count) == err)
		return (err);
	free(numc);
	return (ok);
}

t_status	pf_hex_upper(va_list p_args, ssize_t *count)
{
	unsigned int	num;
	char			*numc;

	num = va_arg(p_args, unsigned int);
	numc = ft_utox(num);
	ft_striteri(numc, ft_strup_iter);
	if (!numc)
		return (err);
	if (pf_write_str(numc, count) == err)
		return (err);
	free(numc);
	return (ok);
}

t_status	pf_pointer(va_list p_args, ssize_t *count)
{
	unsigned long int	pointer;
	char				*numc;

	pointer = va_arg(p_args, unsigned long int);
	if (!pointer)
	{
		if (pf_write_null(count) == err)
			return (err);
		return (ok);
	}
	numc = ft_ltox(pointer);
	if (!numc)
		return (err);
	numc = pf_add_hex_identifier(numc);
	if (!numc)
		return (err);
	if (pf_write_str(numc, count) == err)
		return (err);
	free(numc);
	return (ok);
}
