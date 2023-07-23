/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 05:37:52 by andresj           #+#    #+#             */
/*   Updated: 2023/07/21 08:44:58 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_buffer(unsigned long int num, char *buffer, int count);
char static	*init_number(size_t len, unsigned long int num);

char	*ft_ltox(unsigned long int num)
{
	char	*hex;
	char	buffer[12];
	int		len;

	len = 0;
	ft_bzero(buffer, 12);
	get_buffer(num, buffer, len);
	if (!len)
		return (NULL);
	hex = init_number(len, num);
	if (num == 0)
		return (hex);
	else if (!hex)
		return (NULL);
	ft_strlcpy(hex, buffer, len);
	return (hex);
}

char static	*init_number(size_t len, unsigned long int num)
{
	char	*hex;

	hex = (char *) malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len + 1] = NULL;
	if (num == 0)
		hex[0] = '0';
	return (hex);
}

static void	get_buffer(unsigned long int big, char *buffer, int count)
{
	int					j;
	int					smol;

	if (big == 0)
	{
		count = 3;
		return ;
	}
	j = 16;
	while (j-- >= 0)
	{
		smol = big % 0x10;
		if (smol < 10)
			buffer[j] = (smol + '0');
		else
			buffer[j] = ((smol - 10) + 'a');
		big /= 0x10;
	}
}
