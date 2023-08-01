/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:02:18 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 10:58:04 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

t_status	pf_char(va_list p_args, ssize_t *count)
{
	int	c;

	c = va_arg(p_args, int);
	if (pf_write_char((char) c, count) == err)
		return (err);
	return (ok);
}

t_status	pf_str(va_list p_args, ssize_t *count)
{
	char	*s1;

	s1 = va_arg(p_args, char *);
	if (!s1)
	{
		if (pf_write_str("(null)", count) == err)
			return (err);
		return (ok);
	}
	if (pf_write_str(s1, count) == err)
		return (err);
	return (ok);
}

t_status	pf_percent(ssize_t *count)
{
	if (pf_write_char('%', count) == err)
		return (err);
	return (ok);
}
