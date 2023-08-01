/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 05:37:52 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:27:39 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static void	get_buffer(unsigned long long num, char *buffer, int *count);
char static	*init_number(size_t len, unsigned long long num);

char	*ft_lltox(unsigned long long num)
{
	char	*hex;
	char	buffer[15];
	int		len;

	len = 0;
	ft_bzero(buffer, 15);
	get_buffer(num, buffer, &len);
	if (!len)
		return (NULL);
	hex = init_number(len, num);
	if (num == 0)
		return (hex);
	else if (!hex)
		return (NULL);
	ft_strlcpy(hex, buffer, len);
	ft_strrev(hex);
	return (hex);
}

char static	*init_number(size_t len, unsigned long long num)
{
	char	*hex;

	hex = (char *) ft_calloc(len, sizeof(char));
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	if (num == 0)
		hex[0] = '0';
	return (hex);
}

static void	get_buffer(unsigned long long big, char *buffer, int *count)
{
	const char	hex_digits[17] = "0123456789abcdef";

	if (big == 0)
	{
		*count = 1;
		return ;
	}
	while (big != 0)
	{
		buffer[(*count)++] = hex_digits[big & 0xF];
		big >>= 4;
	}
	(*count)++;
}
