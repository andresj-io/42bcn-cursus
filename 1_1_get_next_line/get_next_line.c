/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/04 15:53:56 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_string	left_over;
	t_read			data;

	if (fd < 0 || ((size_t)BUFFER_SIZE <= 0))
		return (NULL);
	data.buffer = (char *) malloc(sizeof(char) *((size_t)BUFFER_SIZE + 1));
	if (!data.buffer)
		return (NULL);
	data.cnt.ix = 0;
	data.cnt.size = 0;
	data.lo.ix = 0;
	data.lo.str = 0;
	if (left_over.ix)
	{
		data.lo.ix = left_over.ix;
		data.lo.str = left_over.str;
	}
	read_line(fd, &data);
	if (data.lo.str)
	{
		left_over.ix = data.lo.ix;
		left_over.str = data.lo.str;
	}
	return (data.cnt.str);
}

void	read_line(int fd, t_read *data)
{
	ssize_t		nr;

	nr = 1;
	while (nr > 0)
	{
		nr = read(fd, data->buffer, (size_t)BUFFER_SIZE);
		if (nr < 0)
		{
			free_strings(data->aux, data->buffer, data->cnt.str, data->lo.str);
			return ;
		}
		data->buffer[(int)BUFFER_SIZE] = '\0';
		add_content(data);
		if (!data->buffer)
			return ;
		add_left_over(data);
		if (!data->buffer)
			return ;
		if (data->nl_index != 0)
			break ;
	}
}

void	add_content(t_read *data)
{
	data->cnt.size = get_content_size(data);
	if (data->cnt.ix > 0)
		data->aux = dup_str(data->cnt.str);
	data->cnt.str = (char *)malloc(sizeof(char) * data->cnt.size);
	if (!data->cnt.str)
	{
		free_strings(data->aux, data->buffer, data->lo.str, NULL);
		return ;
	}
	if (data->cnt.ix > 0)
	{
		str_copy(data->cnt.str, data->aux);
		free_strings(data->aux, NULL, NULL, NULL);
	}
	str_append(&data->cnt, data->buffer, 0, data->nl_index);
	data->cnt.str[data->cnt.ix] = '\0';
}

size_t	get_content_size(t_read *data)
{
	bool	eol;

	eol = false;
	data->nl_index = 0;
	while (*(data->buffer + data->nl_index) != '\n' \
		&& *(data->buffer + data->nl_index))
	{
		data->nl_index++;
		eol = true;
	}
	if (*data->buffer == '\n')
		return (data->cnt.size + data->nl_index + 2);
	else if (eol == true)
		data->nl_index++;
	else
		data->nl_index = BUFFER_SIZE;
	return (data->cnt.size + data->nl_index + 1);
}

void	add_left_over(t_read *data)
{
	if (data->lo.ix > 0)
		data->aux = dup_str(data->lo.str);
	data->lo.size = data->lo.size + BUFFER_SIZE - data->nl_index;
	data->lo.str = (char *)malloc(sizeof(char) * data->lo.size);
	if (!data->cnt.str)
	{
		free_strings(data->aux, data->buffer, data->cnt.str, NULL);
		return ;
	}
	if (data->lo.ix > 0)
	{
		str_copy(data->lo.str, data->aux);
		free_strings(data->aux, NULL, NULL, NULL);
	}
	str_append(&data->lo, data->buffer, data->nl_index, BUFFER_SIZE);
}
