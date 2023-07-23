/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 06:42:46 by andresj           #+#    #+#             */
/*   Updated: 2023/07/20 06:46:47 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strrev(char *str, int size)
{
	int		start;
	int		end;
	char	aux;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		aux = str[start];
		str[start] = str[end];
		str[end] = aux;
		start++;
		end--;
	}
}
