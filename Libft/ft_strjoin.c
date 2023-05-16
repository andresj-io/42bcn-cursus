/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:36:39 by andresj           #+#    #+#             */
/*   Updated: 2023/05/09 22:49:45 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*concat;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, s1_len);
	ft_strlcpy(concat + s1_len, s2, s2_len);
	concat[s1_len + s2_len + 1] = '\0';
	return (concat);
}