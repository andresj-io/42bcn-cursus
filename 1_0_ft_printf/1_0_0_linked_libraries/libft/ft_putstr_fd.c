/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:43:49 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:33:50 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	return (write(fd, s, len));
}
