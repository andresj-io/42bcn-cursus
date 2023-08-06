/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/06 17:39:15 by andresj          ###   ########.fr       */
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

typedef struct s_read
{
	char	*content;
	int		nl_ix;
	ssize_t	nr;
}	t_read;

char	*get_next_line(int fd);
void	read_until(int fd, t_read *data, char **lo);
void	add_content(t_read *data, char *buffer);
char	*parse(t_read *data);
char	*get_left_over(t_read *data, int len);
void	gnl_free(char **p);
char	*gnl_str_dup(char *src, int len);
void	gnl_str_append(char *dst, const char *src, int from, int to);
int		gnl_search_nl(char *str);
int		gnl_strlen(const char *str);

#endif