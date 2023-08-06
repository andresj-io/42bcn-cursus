/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/06 04:19:31 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_over = NULL;
	t_read		data;

	if (fd < 0 || ((size_t)BUFFER_SIZE <= 0))
		return (NULL);
	if (left_over)
		data.nl_ix = gnl_search_nl(left_over);
	else
		data.nl_ix = -1;
	data.nr = 1;
	data.content = left_over;
	while (data.nl_ix == -1 && data.nr > 0)
	{
		if (read_until(fd, &data) == err)
			return (NULL);
	}
	left_over = parse(&data);
	if (!data.content)
	{
		if (left_over)
			free(left_over);
	}
	return (data.content);
}

t_status	read_until(int fd, t_read *data)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) *((size_t)BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(data->content);
		return (err);
	}
	data->nr = read(fd, buffer, (size_t)BUFFER_SIZE);
	if (data->nr == -1)
	{
		free(buffer);
		if (data->content)
			free(data->content);
		return (err);
	}
	if (set_new_content(data, buffer) == err)
	{
		free(buffer);
		return (err);
	}
	free(buffer);
	return (ok);
}

t_status	set_new_content(t_read *data, char *buffer)
{
	int		len;

	if (data->content)
	{
		if (save_old_content(data, &len) == err)
			return (err);
	}
	else
	{
		if (/* condition */)
		{
			/* code */
		}

		len = 1;
		data->content = (char *) malloc(sizeof(char) * (data->nr + 1));
		*(data->content + data->nr + 1) = '\0';
		if (!data->content)
			return (err);
	}
	gnl_str_append(data->content, buffer, 0, len + data->nr);
	data->nl_ix = gnl_search_nl(data->content);
	return (ok);
}

char	*parse(t_read *data)
{
	int		len;
	int		r_len;
	char	*lo;

	lo = NULL;
	len = gnl_strlen(data->content);
	r_len = len;
	if (data->nl_ix != -1)
	{
		lo = get_left_over(data, len, &r_len);
		if (!lo)
		{
			free(data->content);
			return (NULL);
		}
		*(data->content + data->nl_ix + 1) = '\0';
	}
	else if (data->nl_ix == -1 && data->nr == 0 && len == 0)
	{
		free(data->content);
		data->content = NULL;
	}
	else
		*(data->content + r_len) = '\0';
	return (lo);
}

char	*get_left_over(t_read *data, int len, int *r_len)
{
	char	*lo;
	int		lo_len;

	lo = NULL;
	lo_len = 0;
	if (data->nl_ix)
		lo_len = len - data->nl_ix;
	else
		lo_len = len - 1;
	*r_len = len - lo_len;
	lo = (char *) malloc(sizeof(char) * (lo_len));
	if (!lo)
	{
		if (data->content)
			free(data->content);
		return (NULL);
	}
	gnl_str_append(lo, data->content, data->nl_ix + 1, len);
	if (data->nl_ix)
		data->content[data->nl_ix + 1] = '\0';
	else
		data->content[len + 1] = '\0';
	return (lo);
}
