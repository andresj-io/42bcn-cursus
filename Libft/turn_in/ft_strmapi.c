/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:41:33 by andresj           #+#    #+#             */
/*   Updated: 2023/05/13 20:06:19 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*conv;

	conv = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!conv)
		return (NULL);
	ft_strlcpy(conv, s, ft_strlen(s));
	i = 0;
	while (s[i])
		conv[i++] = (f(0, s[i]));
	return (conv);
}