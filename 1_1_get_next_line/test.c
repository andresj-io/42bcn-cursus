/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:00:58 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/06 17:33:02 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

static void	iterate_file(int fd);

int	main(void)
{
	int			i;
	const char	*files[] = {
		"tests/files/000_empty", "tests/files/001_nl",
		"tests/files/002_41_no_nl", "tests/files/003_41_with_nl",
		"tests/files/004_42_no_nl", "tests/files/005_42_with_nl",
		"tests/files/006_43_no_nl", "tests/files/007_43_with_nl",
		"tests/files/008_multiple_nlx5", "tests/files/009_multiple_line_no_nl",
		"tests/files/010_multiple_line_with_nl",
		"tests/files/011_alternate_line_nl_no_n",
		"tests/files/012_alternate_line_nl_with_nl",
		"tests/files/013_big_line_no_nl", "tests/files/014_big_line_with_nl",
	};

	i = init();
	while (files[i])
	{
		printf("\n%sTest: %02i%s\n", BLUE, i, RESET);
		test_file(files[i]);
		i++;
	}
}

// "tests/files/020.txt", "tests/files/021_1char.txt",
// "tests/files/022_one_line_no_nl.txt", "tests/files/023_only_nl.txt",
// "tests/files/024_multiple_nl.txt", "tests/files/025_variable_nls.txt",
// "tests/files/026_lines_around_10.txt", "tests/files/029_read_error.txt"
// "tests/files/027_giant_line.txt",
// "tests/files/028_giant_line_nl.txt",
// test_stdin();
// test_stdout();
// test_stderr();

int	init(void)
{
	int			i;

	i = 0;
	printf("%sStarting tests%s\n", BLUE, RESET);
	printf(" BUFFER_SIZE = %s%i%s", YELLOW, BUFFER_SIZE, RESET);
	return (i);
}

void	test_file(const char *path)
{
	int		fd;

	printf(" %s%s%s\n", GREEN, path, RESET);
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
			printf("\n\t%sline %03i: %s%s\n", YELLOW, line_q, RESET, "No line!");
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
