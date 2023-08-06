/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:00:58 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/06 14:52:07 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

static void	iterate_file(int fd);

int	main(void)
{
	const char	*files[] = {"tests/files/41_no_nl", "tests/files/41_with_nl", \
		"tests/files/42_no_nl", "tests/files/42_with_nl", \
		"tests/files/43_no_nl", "tests/files/43_with_nl", \
		"tests/files/alternate_line_nl_no_nl", \
		"tests/files/alternate_line_nl_with_nl", \
		"tests/files/big_line_no_nl", \
		"tests/files/big_line_with_nl", "tests/files/empty", \
		"tests/files/multiple_line_no_nl", "tests/files/multiple_line_with_nl",
		"tests/files/multiple_nlx5", "tests/files/nl", \
		"tests/files/test_1char", "tests/files/test_20nl", \
		"tests/files/test_basic", "tests/files/test_empty", \
		"tests/files/test_nl", "tests/files/test_no_nl"\
	};
	int			i;

	i = 0;
	printf("%sStarting tests%s\n", BLUE, RESET);
	printf(" BUFFER_SIZE = %s%i%s", YELLOW, BUFFER_SIZE, RESET);
	while (files[i])
	{
		test_file(files[i]);
		i++;
	}
}
	// test_stdin();
	// test_stdout();
	// test_stderr();
	// test_file("tests/test_basic");
	// test_file("tests/test_empty");
	// test_file("tests/test_1char");
	// test_file("tests/test_nl");
	// test_file("tests/test_20nl");

void	test_file(const char *path)
{
	int		fd;

	printf("\n");
	printf("%s%s%s\n", GREEN, path, RESET);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, path, 15);
		write(1, "File not found\n", 15);
		return ;
	}
	iterate_file(fd);
	close (fd);
	printf("\n");
}

static void	iterate_file(int fd)
{
	int		line_q;
	int		flag;
	char	*line;

	line_q = 0;
	flag = true;
	line = NULL;
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
		{
			printf("\t%sline %03i: %s%s", YELLOW, line_q, RESET, line);
			free(line);
		}
		line_q++;
	}
}
