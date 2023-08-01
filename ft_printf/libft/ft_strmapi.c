/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:41:33 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:34:44 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*conv;

	conv = ft_strdup(s);
	if (!conv)
		return (NULL);
	i = 0;
	while (s[i])
	{
		conv[i] = (f(i, s[i]));
		i++;
	}
	return (conv);
}
