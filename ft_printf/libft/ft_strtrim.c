/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:50:11 by andresj           #+#    #+#             */
/*   Updated: 2023/07/31 18:48:59 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

t_status static	seek(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	size;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (seek(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	end--;
	while (seek(s1[end], set))
		end--;
	size = end - start + 2;
	trimmed = (char *)malloc(sizeof(char) * size);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, size);
	return (trimmed);
}

t_status static	seek(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (ok);
		i++;
	}
	return (err);
}
