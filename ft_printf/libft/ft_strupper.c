/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:57:46 by andresj           #+#    #+#             */
/*   Updated: 2023/07/31 18:48:53 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_strup_iter(unsigned int i, char *c)
{
	if (i)
		*(c) = ft_toupper(*(c));
	else
		*(c) = ft_toupper(*(c));
}
