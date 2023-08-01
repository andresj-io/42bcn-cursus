/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:38:18 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 12:23:17 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int static	get_figures(unsigned int n);
char static	*init_number(size_t len, int n);

char	*ft_utoa(unsigned int ui)
{
	int		len;
	char	*number;

	len = get_figures(ui);
	number = init_number(len, ui);
	if (!number)
		return (NULL);
	while (ui != 0)
	{
		number[--len] = (ui % 10) + '0';
		ui /= 10;
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
	if (n == 0)
		number[0] = '0';
	return (number);
}

int static	get_figures(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
