/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:38 by andresj           #+#    #+#             */
/*   Updated: 2023/07/23 05:03:11 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status	find_needle(char const *haystack, char const *needle);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	nlen = ft_strlen(needle);
	if (!(*(needle)) || len < 0)
		return ((char *) haystack);
	while (haystack[i] && i <= len)
	{
		if (haystack[i] == *needle && (nlen <= len - i)
			&& find_needle(haystack + i, needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

t_status	find_needle(char const *haystack, char const *needle)
{
	int	i;

	i = 0;
	while (*(needle + i))
	{
		if (*(haystack + i) != *(needle + i))
			return (err);
		i++;
	}
	return (ok);
}