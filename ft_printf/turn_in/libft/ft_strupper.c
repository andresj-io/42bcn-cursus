/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:57:46 by andresj           #+#    #+#             */
/*   Updated: 2023/07/21 04:24:57 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strup_iter(unsigned int i, char *c)
{
	c[i] = ft_toupper(c[i]);
}

char	ft_strup_mapi(unsigned int i, char c)
{
	char	upper;

	upper = ft_toupper(c);
}
