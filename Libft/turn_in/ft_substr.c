/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:26:14 by andresj           #+#    #+#             */
/*   Updated: 2023/05/09 22:39:49 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	subs = (char *) malloc(sizeof(char) * len + 1);
	if (!subs)
		return (NULL);
	i = 0;
	while (len--)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}