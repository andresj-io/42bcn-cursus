/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:26:14 by andresj           #+#    #+#             */
/*   Updated: 2023/07/31 18:48:47 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	subs = (char *) malloc(sizeof(char) * len + 1);
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
