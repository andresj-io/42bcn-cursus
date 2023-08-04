/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/04 12:10:56 by ajacome-         ###   ########.fr       */
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

typedef struct s_string
{
	char	*str;
	ssize_t	size;
	int		ix;
}	t_string;

typedef struct s_read
{
	t_string	cnt;
	t_string	lo;
	char		*buffer;
	char		*aux;
	int			nl_index;
}	t_read;

char	*get_next_line(int fd);
void	read_line(int fd, t_read *store);
size_t	get_content_size(t_read *data);
void	add_content(t_read *data);
void	add_left_over(t_read *data);
void	free_strings(char *s1, char *s2, char *s3, char *s4);
char	*dup_str(const char *s1);
void	str_copy(char *dst, const char *src);
void	str_append(t_string *dst, const char *src, int from, int to);
char	*concat_str(const char *s1, const char *s2);

#endif