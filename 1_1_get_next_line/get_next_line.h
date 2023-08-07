/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/06 20:18:09 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_string
{
	char	*s;
	int		ix;
}	t_string;

typedef struct s_read
{
	int		nl_ix;
	ssize_t	nr;
}	t_read;

char	*get_next_line(int fd);
void	gnl_str_append(t_string *dst, t_string *src, int from, int to);
int		gnl_search_nl(char *str);
void	gnl_free(t_string *p);

#endif