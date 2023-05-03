/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:30:01 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 16:31:56 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	static is_digit(int c);
int	static is_upper(int c);
int	static is_lower(int c);

int	ft_isalnum(int c)
{
	if (is_upper(c) || is_lower(c) || is_digit(c))
		return (1);
	return (0);
}

int	static is_upper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	static is_lower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	static is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
