/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:00:58 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/05 16:21:49 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	test_file("tests/test_file1");
	test_file("tests/test_file2");
	test_stdin();
	test_stdout();
	test_stderr();
}

void	test_stdin(void)
{
	return ;
}

void	test_stdout(void)
{
	return ;
}

void	test_stderr(void)
{
	return ;
}

void	test_file(const char *path)
{
	int		fd;
	int		line_q;
	char	*line;

	line_q = 0;
	printf("\n%s%s%s\n", GREEN, path, RESET);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, path, 15);
		write(1, "File not found\n", 15);
		return ;
	}
	while (++line_q <= 7)
	{
		line = get_next_line(fd);
		if (!line)
			printf("\t%sline %i:\t%s%s\n", YELLOW, line_q, RESET, "No line!");
		else
			printf("\t%sline %i:\t%s%s", YELLOW, line_q, RESET, line);
	}
	close (fd);
	printf("\n");
}
