/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:00:58 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/05 19:39:27 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

static void	iterate_file(int fd);

int	main(void)
{
	printf("%sStarting tests%s\n", BLUE, RESET);
	printf(" BUFFER_SIZE = %s%i%s", YELLOW, BUFFER_SIZE, RESET);
	test_file("tests/test_basic");
	printf("\n");
	test_file("tests/test_empty");
	printf("\n");
	test_file("tests/test_nl");
	printf("\n");
	test_file("tests/test_20nl");
	printf("\n");
	test_stdin();
	test_stdout();
	test_stderr();
}

void	test_file(const char *path)
{
	int		fd;

	printf("\n%s%s%s\n", GREEN, path, RESET);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, path, 15);
		write(1, "File not found\n", 15);
		return ;
	}
	iterate_file(fd);
	close (fd);
}

static void	iterate_file(int fd)
{
	int		line_q;
	int		flag;
	char	*line;

	line_q = 0;
	flag = true;
	while (flag || line)
	{
		flag = false;
		line = get_next_line(fd);
		if (!line)
		{
			printf("\t%sline %03i: %s%s\n", YELLOW, line_q, RESET, "No line!");
			break ;
		}
		else
			printf("\t%sline %03i: %s%s", YELLOW, line_q, RESET, line);
		line_q++;
	}
}
