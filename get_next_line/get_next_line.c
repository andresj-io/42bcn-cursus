/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/02 13:55:17 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*content;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	nr;
	ssize_t	size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[BUFFER_SIZE + 1] = '\0';
	nr = read(fd, buffer, BUFFER_SIZE);
	while (*buffer)
	{
		
	}
	
	if (nr < BUFFER_SIZE)
		size = BUFFER_SIZE - nr;
	else
		size = BUFFER_SIZE;
	content = (char *) malloc(sizeof(char) * (size + 1));
	if (!content)
		return (NULL);
	
}
