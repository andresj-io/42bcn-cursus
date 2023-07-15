/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:35:17 by andresj           #+#    #+#             */
/*   Updated: 2023/07/13 16:47:37 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				r;
	unsigned int	i;

	r = 0;
	i = 0;
	while ((i < n) && (*(s1 + i) || *(s2 + i)))
	{
		r = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (0);
}
