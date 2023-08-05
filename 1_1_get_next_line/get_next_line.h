/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/05 15:11:09 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

typedef enum e_status
{
	err,
	ok,
}	t_status;

typedef struct s_string
{
	char	*str;
	int		ix;
	ssize_t	size;
}	t_string;

typedef struct s_read
{
	char		*content;
	int			nl_ix;
	ssize_t		nr;
}	t_read;

char		*get_next_line(int fd);
t_status	set_new_content(t_read *data, char *buffer);
t_status	save_old_content(t_read *data, int *len);
char		*parse(t_read *data);
t_status	read_until(int fd, t_read *data);
char		*get_left_over(t_read *data, int len, int *r_len);
void		gnl_str_append(char *dst, const char *src, int from, int to);
int			gnl_search_nl(char *str);
int			gnl_strlen(const char *str);
char		*gnl_str_dup(char *src);

#endif