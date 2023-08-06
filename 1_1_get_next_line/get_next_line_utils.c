/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:58:07 by andresj           #+#    #+#             */
/*   Updated: 2023/08/06 14:03:49 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_free(char **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
}

int	gnl_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (*(str + len))
		len++;
	return (len);
}

char	*gnl_str_dup(char *src, int len)
{
	char	*new;

	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	if (!*src && len > 0)
	{
		new[0] = '\0';
		return (new);
	}
	len = -1;
	while (*(src + ++len))
		*(new + len) = *(src + len);
	*(new + len) = '\0';
	return (new);
}

void	gnl_str_append(char *dst, const char *src, int from, int to)
{
	int	d_len;

	d_len = 0;
	if (dst)
	{
		while (*(dst + d_len))
			d_len++;
	}
	while (from < to)
	{
		*(dst + d_len) = *(src + from);
		from++;
		d_len++;
	}
}

int	gnl_search_nl(char *str)
{
	int	nl_ix;

	nl_ix = 0;
	if (!str || !*str)
		return (-1);
	while (*(str + nl_ix))
	{
		if (*(str + nl_ix) == '\n')
		{
			return (nl_ix);
		}
		nl_ix++;
	}
	return (-1);
}
