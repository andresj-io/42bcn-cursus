/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:36:39 by andresj           #+#    #+#             */
/*   Updated: 2023/07/13 18:12:42 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, s1_len + 1);
	ft_strlcpy(concat + s1_len, s2, s2_len + 1);
	return (concat);
}
