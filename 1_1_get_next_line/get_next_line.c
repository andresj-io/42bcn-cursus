/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/03 10:49:21 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left_over = NULL;
	t_read	store;

	if (fd < 0 || (size_t)BUFFER_SIZE <= 0)
		return (NULL);
	store.buffer = (char *) malloc(sizeof(char) *((size_t)BUFFER_SIZE + 1));
	if (!store.buffer)
		return (NULL);
	read_line(fd, &store);
	return (store.cnt);
}

void	read_line(int fd, t_read *store)
{
	ssize_t		nr;
	ssize_t		size;
	bool		eol;

	while (nr > 0)
	{
		nr = read(fd, store->buffer, (size_t)BUFFER_SIZE);
		if (nr < 0)
		{
			free_store(&store);
			return ;
		}
		else if (nr < (size_t)BUFFER_SIZE)
			size = (size_t)BUFFER_SIZE - nr;
		else
			size = (size_t)BUFFER_SIZE;
		store->cnt->str = (char *)malloc(sizeof(char)* size);
		if (!store->cnt->str)
			return (NULL);
		store->buffer[(int)BUFFER_SIZE] = '\0';
		eol = false;
		parse_read(&eol, store);
		if (eol == true)
			break ;
	}
}

void	parse_read(bool *eol, t_read *store)
{
	while (*(store->buffer))
	{
		if (eol = false)
		{
			*(store->cnt->str + store->cnt->index++) = *(store->buffer++);
			if (*(store->buffer) == '\n')
				eol = true;
		}
		else if (eol = true)
			*(store->lo->str + store->lo->index++) = *(store->buffer++);
	}
}
