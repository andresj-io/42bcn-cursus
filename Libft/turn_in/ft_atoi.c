/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:11 by andresj           #+#    #+#             */
/*   Updated: 2023/07/11 06:51:57 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		static is_space(char c);
int		static is_number(char c);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_number(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}	
	return (number * sign);
}

int	static is_space(char c)
{
	if ((c == ' ') || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int		static is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
