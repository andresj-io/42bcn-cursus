/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/06 21:24:12 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_over;
	t_read		data;

	if (fd < 0 || ((size_t)BUFFER_SIZE <= 0))
		return (NULL);
	data.nr = 1;
	data.content = NULL;
	data.nl_ix = -1;
	if (left_over)
	{
		data.content = gnl_str_dup(left_over, gnl_strlen(left_over));
		free(left_over);
		left_over = NULL;
		if (!data.content)
			return (NULL);
		data.nl_ix = gnl_search_nl(data.content);
	}
	read_until(fd, &data, &left_over);
	if (data.content)
		left_over = parse(&data);
	return (data.content);
}

void	read_until(int fd, t_read *data, char **lo)
{
	char	buffer[BUFFER_SIZE + 1];

	while (data->nl_ix == -1 && data->nr > 0)
	{
		data->nr = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (data->nr > 0)
		{
			*(buffer + data->nr) = '\0';
			add_content(data, buffer);
			if (data->content)
				data->nl_ix = gnl_search_nl(data->content);
			else
				break ;
		}
	}
	if (data->nr < 0)
	{
		gnl_free(lo);
		gnl_free(&(data->content));
	}
}

void	add_content(t_read *data, char *buffer)
{
	int		len;
	char	*aux;

	len = gnl_strlen(data->content);
	if (len)
	{
		aux = gnl_str_dup(data->content, len);
		gnl_free(&data->content);
		if (!aux)
			return ;
		data->content = gnl_str_dup(aux, len + data->nr);
		gnl_free(&aux);
		if (!data->content)
			return ;
		gnl_str_append(data->content, buffer, 0, data->nr + 1);
	}
	else
		data->content = gnl_str_dup(buffer, data->nr);
}

char	*parse(t_read *data)
{
	char	*lo;
	int		len;

	lo = NULL;
	len = gnl_strlen(data->content);
	if ((data->nl_ix != -1) && (*(data->content + data->nl_ix + 1)))
	{
		lo = get_left_over(data, len);
		if (!lo)
		{
			gnl_free(&data->content);
			return (NULL);
		}
	}
	if (data->nl_ix >= 0)
		data->content[data->nl_ix + 1] = '\0';
	else
		data->content[len] = '\0';
	return (lo);
}

char	*get_left_over(t_read *data, int len)
{
	char	*lo;
	int		lo_len;

	lo = NULL;
	lo_len = 0;
	if (data->nl_ix)
		lo_len = len - data->nl_ix;
	else
		lo_len = len - 1;
	lo = gnl_str_dup("", lo_len);
	if (!lo)
		return (NULL);
	gnl_str_append(lo, data->content, data->nl_ix + 1, len);
	lo[lo_len] = '\0';
	return (lo);
}
