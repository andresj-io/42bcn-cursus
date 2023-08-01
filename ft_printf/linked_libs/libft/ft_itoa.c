/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:49:27 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:27:33 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char		*ft_itoa(int n);
int static	get_figq(int n);
char static	*init_number(size_t len, int n);

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*number;

	len = get_figq(n);
	number = init_number(len, n);
	if (!number)
		return (NULL);
	num = 0;
	if (n < 0)
		num = n * -1;
	else
		num = n;
	while (num > 0)
	{
		number[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (number);
}

char static	*init_number(size_t len, int n)
{
	char	*number;

	number = (char *) malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	number[len] = '\0';
	if (n < 0)
		number[0] = '-';
	else if (n == 0)
		number[0] = '0';
	return (number);
}

int static	get_figq(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
