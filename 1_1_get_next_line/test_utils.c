/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:22:09 by andresj           #+#    #+#             */
/*   Updated: 2023/08/09 10:46:18 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

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
		printf("%s%s %sFile not found%s\n", GREEN, path, RED, RESET);
		return ;
	}
	iterate_file(fd);
	close (fd);
	printf("\n");
}