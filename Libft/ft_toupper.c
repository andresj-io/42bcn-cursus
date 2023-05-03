/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:33:30 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 21:18:28 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	static is_lower(int c);

int	ft_toupper(int c)
{
	if (is_lower(c))
		c -= ' ';
	return (c);
}

int	static is_lower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
