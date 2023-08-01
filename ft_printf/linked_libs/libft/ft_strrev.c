/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:42:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:35:22 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_strrev(char *str)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		aux = str[start];
		str[start] = str[end];
		str[end] = aux;
		start++;
		end--;
	}
}
