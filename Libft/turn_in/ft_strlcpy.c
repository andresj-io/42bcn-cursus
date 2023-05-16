/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:33:36 by andresj           #+#    #+#             */
/*   Updated: 2023/05/04 08:40:29 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	const char	*s;
	size_t			n;

	n = dstsize;
	s = src;
	if (n != 0)
	{
		while (--n || *s)
			*dst++ = *s++;
	}
	if (n == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*s++);
	}
	return (s - src - 1);
}
