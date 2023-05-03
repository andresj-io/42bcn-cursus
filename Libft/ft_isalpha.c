/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:37:08 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 16:28:43 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	static is_upper(int c);
int	static is_lower(int c);

int	ft_isalpha(int c)
{
	if (is_upper(c) || is_lower(c))
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
