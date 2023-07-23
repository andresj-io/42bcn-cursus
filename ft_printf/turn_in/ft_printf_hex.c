/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 05:06:07 by andresj           #+#    #+#             */
/*   Updated: 2023/07/23 05:01:12 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
t_status	pf_hex(const char *str, int *pos, va_list *p_args, ssize_t *count)
{
	unsigned int	num;
	char					*numc;

	num = va_arg(p_args, unsigned int);
	numc = ft_utox(num);
	if (!numc)
		return (err);
	if (write_str(numc, &count) == err)
		return (err);
	return (ok);
}
*/

t_status	pf_hex_lower(const char *str, va_list *p_args, ssize_t *count)
{
	char					*numc;
	unsigned int	num;

	num = va_arg(p_args, unsigned int);
	numc = ft_utox(num);
	if (!numc)
		return (err);
	if (pf_write_str(numc, &count) == err)
		return (err);
	str++;
	return (ok);
}

t_status	pf_hex_upper(const char *str, va_list *p_args, ssize_t *count)
{
	unsigned int	num;
	char					*numc;

	num = va_arg(p_args, unsigned int);
	numc = ft_utox(num);
	ft_striteri(numc, ft_strup_iter);
	if (!numc)
		return (err);
	if (pf_write_str(numc, &count) == err)
		return (err);
	str++;
	return (ok);
}

t_status	pf_pointer(const char *str, va_list *p_args, ssize_t *count)
{
	unsigned long int	pointer;
	char							*numc;

	pointer = va_arg(p_args, unsigned long int);
	if (!pointer && pf_write_null(count) == err)
		return (err);
	numc = ft_ltox(pointer);
	if (!numc)
		return (err);
	numc = pf_add_hex_identifier(numc);
	if (!numc)
		return (err);
	if (pf_write_str(numc, &count) == err)
		return (err);
	str++;
	return (ok);
}
