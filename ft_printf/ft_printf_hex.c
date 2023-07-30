/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 05:06:07 by andresj           #+#    #+#             */
/*   Updated: 2023/07/28 07:47:06 by andresj          ###   ########.fr       */
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
	{
		free(numc);
		return (err);
	}
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
	{
		free(numc);
		return (err);
	}
	free(numc);
	return (ok);
}

t_status	pf_pointer(va_list p_args, ssize_t *count)
{
	void	*pointer;
	char	*numl;
	char	*out;

	pointer = va_arg(p_args, void *);
	if (!pointer)
	{
		if (pf_write_str("0x0", count) == err)
			return (err);
		return (ok);
	}
	numl = ft_lltox((unsigned long long)pointer);
	if (!numl)
		return (err);
	out = pf_add_hex_identifier(numl);
	free(numl);
	if (!out)
		return (err);
	if (pf_write_str(out, count) == err)
	{
		free(out);
		return (err);
	}
	free(out);
	return (ok);
}
