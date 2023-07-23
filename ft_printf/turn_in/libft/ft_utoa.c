/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:38:18 by ajacome-          #+#    #+#             */
/*   Updated: 2023/07/20 04:01:39 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	number[len] = NULL;
	if (n == 0)
		number[0] = '0';
	return (number);
}

int static	get_figures(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}