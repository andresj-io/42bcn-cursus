/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:49:27 by andresj           #+#    #+#             */
/*   Updated: 2023/05/14 13:02:26 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n);
int		static get_figq(int n);

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*number;

	len = get_figq(n);
	number = (char *) malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	i = 0;
	while (n / 10)
	{
		number[i++] = n % 10;
		n /= 10;
	}
	number[i++] = n % 10;
	number[i] = '\0';
	return (number);
}

int	static get_figq(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len++);
}
