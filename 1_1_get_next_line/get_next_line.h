/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:59:46 by andresj           #+#    #+#             */
/*   Updated: 2023/08/03 10:49:14 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 16
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_string
{
	char	*str;
	int		index;
}	t_string;

typedef struct s_read
{
	t_string	*cnt;
	t_string	*lo;
	char		*buffer;
}	t_read;

char	*get_next_line(int fd);
void	parse_read(bool *eol, t_read *store);
void	read_line(int fd, t_read *store);
void	free_store(t_read *store);

#endif