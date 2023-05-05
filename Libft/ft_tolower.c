/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:34:49 by andresj           #+#    #+#             */
/*   Updated: 2023/05/04 09:00:54 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static is_upper(int c);

int	ft_tolower(int c)
{
	if (is_upper(c))
		c += ' ';
	return (c);
}

int	static is_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
