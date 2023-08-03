/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:46:24 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:33:14 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	printed;

	printed = ft_putstr_fd(s, fd);
	if (printed < 0)
		return (-1);
	if (write(fd, "\n", 1) < 0)
		return (-1);
	return (printed + 1);
}
