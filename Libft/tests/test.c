/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:36 by andresj           #+#    #+#             */
/*   Updated: 2023/07/15 17:32:04 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../turn_in/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <ctype.h>

void	test_atoi(void);
void	test_bzero(void);
void	test_isalpha(void);
void	test_split(void);
void	test_putnbr_fd();

int	main(void)
{
	int		i = 0;
	void	(*tests[])(void) = {test_atoi,\
	test_bzero,\
	test_isalpha,\
	test_split,\
	test_putnbr_fd};
	
	while (i < 5)
	{
		printf("\n*************************************************\n\n");
		printf("TEST: %i\n", i);
		tests[i]();
		i++;
		printf("\n*************************************************\n\n");
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

void	test_split(void)
{
	ft_split("hello!zzzzzzzz", 'z');
	ft_split("                  olol", ' ');
	ft_split("             ", ' ');
	ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
}

void	test_putnbr_fd()
{
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(10, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-548600, 1);
	ft_putchar_fd('\n', 1);
}
