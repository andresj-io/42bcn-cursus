/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:47 by andresj           #+#    #+#             */
/*   Updated: 2023/07/13 16:30:41 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status static	is_match(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (is_match(s + i, c) == ok)
			return ((char *) s + i);
		i++;
	}
	if (is_match(s + i, c) == ok)
		return ((char *) s + i);
	return (NULL);
}

t_status static	is_match(const char *s, int c)
{
	if (*s == (char) c)
		return (ok);
	else
		return (error1);
}
