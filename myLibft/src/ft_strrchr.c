/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:44 by andresj           #+#    #+#             */
/*   Updated: 2023/07/18 10:21:36 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status static	is_match(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (is_match(s + i, c) == ok)
			last = (char *) s + i;
		i++;
	}
	if (is_match(s + i, c) == ok)
		last = (char *) s + i;
	return (last);
}

t_status static	is_match(const char *s, int c)
{
	if (*s == (char) c)
		return (ok);
	else
		return (err);
}
