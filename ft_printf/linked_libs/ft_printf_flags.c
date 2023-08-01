/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:46:19 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 10:58:00 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

char	*pf_add_hex_identifier(char *str)
{
	char	*formated;
	int		len;

	len = ft_strlen(str) + 3;
	formated = ft_calloc(len, sizeof(char *));
	if (!formated)
		return (NULL);
	while (--len)
		formated[len] = str[len - 2];
	formated[0] = '0';
	formated[1] = 'x';
	return (formated);
}
