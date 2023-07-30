/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:42:46 by andresj           #+#    #+#             */
/*   Updated: 2023/07/25 02:35:08 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
