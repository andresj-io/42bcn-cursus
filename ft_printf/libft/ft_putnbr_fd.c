/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:51:50 by andresj           #+#    #+#             */
/*   Updated: 2023/07/17 16:00:01 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	special_cases(int n, int fd);
static int	recursive_put(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (special_cases(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	recursive_put(n, fd);
}

static bool	special_cases(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (true);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return (true);
	}
	else
		return (false);
}

static int	recursive_put(int n, int fd)
{
	char	numc;

	if (n / 10)
	{
		if (recursive_put(n / 10, fd) < 0)
			return (-1);
	}
	numc = '0' + (n % 10);
	return (write(fd, &numc, 1));
}
