/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:57:46 by andresj           #+#    #+#             */
/*   Updated: 2023/07/24 10:21:07 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strup_iter(unsigned int i, char *c)
{
	c[i] = ft_toupper(c[i]);
}

char	ft_strup_mapi(unsigned int i, char c)
{
	if (i)
		return (ft_toupper(c));
	return (ft_toupper(c));
}
