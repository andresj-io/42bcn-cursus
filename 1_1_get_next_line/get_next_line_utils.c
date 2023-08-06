/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:58:07 by andresj           #+#    #+#             */
/*   Updated: 2023/08/06 04:07:36 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_status	save_old_content(t_read *data, int *len)
{
	char	*aux;

	aux = gnl_str_dup(data->content);
	if (!aux)
	{
		free(data->content);
		return (err);
	}
	*len = gnl_strlen(data->content);
	data->content = (char *) malloc(sizeof(char) *(*len + data->nr + 1));
	if (!data->content)
	{
		free(aux);
		return (err);
	}
	gnl_str_append(data->content, aux, 0, *len);
	*(data->content + *len + data->nr + 1) = '\0';
	free(aux);
	return (ok);
}

int	gnl_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char	*gnl_str_dup(char *src)
{
	char	*new;
	int		len1;

	len1 = 0;
	while (*(src + len1))
		len1++;
	new = (char *) malloc(sizeof(char) * (len1 + 1));
	if (!new)
		return (new);
	len1 = -1;
	while (*(src + ++len1))
		*(new + len1) = *(src + len1);
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
