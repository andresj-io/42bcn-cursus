/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 04:01:20 by andresj           #+#    #+#             */
/*   Updated: 2023/07/31 18:48:13 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static void	get_buffer(uint32_t n, char *buffer, int *count);
char static	*init_number(size_t len, int n);

char	*ft_utox(unsigned int ui)
{
	char	*hex;
	char	buffer[10];
	int		len;

	len = 0;
	ft_bzero(buffer, 10);
	get_buffer(ui, buffer, &len);
	if (!len)
		return (NULL);
	hex = init_number(len, ui);
	if (ui == 0)
		return (hex);
	else if (!hex)
		return (NULL);
	ft_strlcpy(hex, buffer, len);
	ft_strrev(hex);
	return (hex);
}

char static	*init_number(size_t len, int n)
{
	char	*hex;

	hex = (char *) malloc(sizeof(char) * len);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	if (n == 0)
		hex[0] = '0';
	return (hex);
}

static void	get_buffer(uint32_t n, char *buffer, int *count)
{
	const char	hex_digits[17] = "0123456789abcdef";

	if (n == 0)
	{
		*count = 1;
		return ;
	}
	while (n != 0)
	{
		buffer[(*count)++] = hex_digits[n & 0xF];
		n >>= 4;
	}
	(*count)++;
}
