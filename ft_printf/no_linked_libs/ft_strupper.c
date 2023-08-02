/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:57:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/02 09:31:35 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	ft_strup_iter(unsigned int i, char *c)
{
	if (i)
		*(c) = ft_toupper(*(c));
	else
		*(c) = ft_toupper(*(c));
}
