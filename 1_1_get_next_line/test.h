/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:33:01 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/09 10:45:47 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

void	test_stdin(void);
int		init(void);
void	test_file(const char *path);
void	iterate_file(int fd);
void	print_result(char *line, int lq);
void	test_stdout(void);
void	test_stderr(void);

#endif