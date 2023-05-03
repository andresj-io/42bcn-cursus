/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:47 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 21:35:13 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len++]);
	while (i < len)
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
