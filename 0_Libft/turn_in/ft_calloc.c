/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:16 by andresj           #+#    #+#             */
/*   Updated: 2023/07/13 11:40:00 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p1;
	size_t	total_size;

	total_size = count * size;
	p1 = malloc(total_size);
	if (p1)
		ft_bzero(p1, total_size);
	return (p1);
}
