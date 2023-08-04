/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:00:58 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/04 15:54:55 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	test_stdin(void);
static void	test_file1(const char *path);
static void	test_stdout(void);
static void	test_stderr(void);

int	main(void)
{
	test_file1("tests/test_file1");
	test_stdin();
	test_stdout();
	test_stderr();
}

static void	test_stdin(void)
{
	return ;
}

static void	test_stdout(void)
{
	return ;
}

static void	test_stderr(void)
{
	return ;
}

static void	test_file1(const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, path, 15);
		write(1, "File not found\n", 15);
	}
	line = get_next_line(fd);
	close (fd);
}
