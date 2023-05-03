/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:36 by andresj           #+#    #+#             */
/*   Updated: 2023/05/02 21:41:59 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <ctype.h>

#include "ft_atoi.c"
#include "ft_bzero.c"
#include "ft_isalpha.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isdigit.c"
#include "ft_isprint.c"
#include "ft_strlen.c"

void	test_atoi(void);
void	test_bzero(void);
void	test_isalpha(void);

int	main(void)
{
	int		i = 0;
	void	(*tests[])(void) = {test_atoi, test_bzero, test_isalpha};
	
	while (i < 3)
	{
		printf("i %i\n", i);
		(tests[i]());
		i++;
	}
}

void	test_atoi(void)
{
	int r1;
	int r2;

	printf("******************** ft_atoi ********************\n");
	printf("atoi\t\tft_atoi:\n");
	r1 = atoi("abc123");
	r2 = ft_atoi("abc123");
	printf("%i\t\t%i\n", r1, r2);
	r1 = atoi("10520");
	r2 = ft_atoi("10520");
	printf("%i\t\t%i\n", r1, r2);
	r1 = atoi("-2147483648");
	r2 = ft_atoi("-2147483648");
	printf("%i\t%i\n", r1, r2);
	r1 = atoi("2147483647");
	r2 = ft_atoi("2147483647");
	printf("%i\t%i\n", r1, r2);
	r1 = atoi("--2147483648");
	r2 = ft_atoi("--2147483648");
	printf("%i\t\t%i\n", r1, r2);
	r1 = atoi("-2147483649");
	r2 = ft_atoi("-2147483649");
	printf("%i\t%i\n", r1, r2);
	r1 = atoi("2147483650");
	r2 = ft_atoi("2147483650");
	printf("%i\t%i\n", r1, r2);
	printf("*************************************************\n\n");
}

void	test_bzero(void)
{
	
}

void	test_isalpha(void)
{
	
}

void test_memset(void)
{
	
}
