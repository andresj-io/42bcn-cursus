/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:38 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:34:53 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

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
