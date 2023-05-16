/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:50:11 by andresj           #+#    #+#             */
/*   Updated: 2023/05/09 23:16:44 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	size_t	size;
	char		*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end < start && ft_strchr(set, s1[end - 1]))
		end--;
	size = end - start + 1;
	trimmed = (char *)malloc(sizeof(char) * size);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, size);
}