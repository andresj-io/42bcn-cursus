/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:38 by andresj           #+#    #+#             */
/*   Updated: 2023/05/17 13:40:50 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*found;
	int		i;

	found = NULL;
	i = 0;
	while (haystack[i] || len--)
	{
		find_needle(haystack + i, needle);
	}
	return (found);
}

find_needle(char *haystack, char *needle)
{
	int	i;

	i = 0;
	while (*(needle + i) || *(haystack + i))
	{
		if (*(haystack + i) != *(needle + i))
		{
			
		}
		
	}
}
