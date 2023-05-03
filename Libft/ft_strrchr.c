/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:44 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 21:36:42 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;

	len = 0;
	while (s[len++]);
	i = len;
	while (i >= 0)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}