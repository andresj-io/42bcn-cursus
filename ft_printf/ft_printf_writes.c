/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 06:13:37 by andresj           #+#    #+#             */
/*   Updated: 2023/07/24 10:11:51 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_status	pf_write_char(char c, ssize_t *count)
{
	if (ft_putchar_fd(c, STDOUT_FILENO) < 0)
		return (err);
	(*count)++;
	return (ok);
}

t_status	pf_write_str(char *str, ssize_t *count)
{
	int		printed;

	printed = ft_putstr_fd(str, STDOUT_FILENO);
	if (printed < 0)
		return (err);
	else
	{
		*count += printed;
		return (ok);
	}
}

t_status	pf_write_null(ssize_t *count)
{
	const char	*nuller = "(null)";

	if (pf_write_str((char *) nuller, count) == err)
		return (err);
	return (ok);
}
