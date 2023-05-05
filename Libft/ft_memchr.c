/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:24 by andresj           #+#    #+#             */
/*   Updated: 2023/05/04 08:19:32 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p;
	size_t i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (*p == (unsigned char) c)
			return (void *) p;
		i++;
		p++;
	}
	return (NULL);
}