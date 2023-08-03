/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:13:54 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/02 11:54:03 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "test.h"

static void	test1(void);
static void	test2(void);

int	main(void)
{
	printf("\n\n%scategory: p%s \n", YELLOW, RESET);
	test_pointers();
	return (0);
}

void	print_result(int result)
{
	if (result)
		printf("%sOK%s\n", GREEN, RESET);
	else
		printf("%sKO%s\n", RED, RESET);
}

void	test_pointers(void)
{
	test1();
	test2();
}

static void	test1(void)
{
	int	ret_ft;
	int	ret_st;

	printf("%sTest 1:%s \n", YELLOW, RESET);
	ft_printf(" ft_printf:\t");
	ret_ft = ft_printf("%p %p", NULL, NULL);
	printf("\treturn: %i\n", ret_ft);
	printf(" printf:\t");
	ret_st = printf("%p %p", NULL, NULL);
	printf("\treturn: %i\n", ret_st);
	printf("%sTest 1 result: %s", YELLOW, RESET);
	print_result(ret_ft == ret_st);
}

static void	test2(void)
{
	int	ret_ft;
	int	ret_st;
	int	aux;

	printf("%sTest 2:%s \n", YELLOW, RESET);
	aux = 42;
	ft_printf(" ft_printf:\t");
	ret_ft = ft_printf("%p", &aux);
	printf("\treturn: %i\n", ret_ft);
	printf(" printf:\t");
	ret_st = printf("%p", &aux);
	printf("\treturn: %i\n", ret_st);
	printf("%sTest 2 result: %s", YELLOW, RESET);
	print_result(ret_ft == ret_st);
}

/*
	// ret = ft_printf("HOLA\n");
	// ret = ft_printf(" NULL %s NULL ", NULL);
	// ret = printf(" %p %p ", NULL, NULL);
	// ret = ft_printf(" %p", &ret);
	// ret = ft_printf(" %p %p ", NULL, NULL);
	// ret = ft_printf("\n");
	// ret = printf(" %u %u %u %u %u %u %u",\
	// 	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ret = ft_printf(" %u %u %u %u %u %u %u",\
	// 	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %x ", -1);
	// ret = ft_printf(" %x ", -1);
	// ret = ft_printf(" %x ", 1);
	// ret = ft_printf(" %x ", 9);
	// ret = ft_printf(" %x ", 10);
	// ret = ft_printf(" %x ", 11);
	// ret = ft_printf(" %x ", 15);
	// ret = ft_printf(" %x ", 16);
	// ret = ft_printf(" %x ", 17);
	// ret = ft_printf(" %x ", 99);
	// ret = ft_printf(" %x ", 100);
	// ret = ft_printf(" %x ", 101);
	// ret = ft_printf(" %x ", -9);
	// ret = ft_printf(" %x ", -10);
	// ret = ft_printf(" %x ", -11);
	// ret = ft_printf(" %x ", -14);
	// ret = ft_printf(" %x ", -15);
	// ret = ft_printf(" %X ", -1);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -9);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -10);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -11);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -14);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -15);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -16);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -99);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -100);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", -101);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", INT_MAX);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", LONG_MAX);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", UINT_MAX);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", ULONG_MAX);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X ", 9223372036854775807LL);
	// ret = ft_printf("\n");
	// ret = ft_printf(" %X %X %X %X %X %X %X",\
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ret = ft_printf("\n");

	// ret = ft_printf(" %p ", -1);
	// ret = ft_printf(" %p ", 1);
	// ret = ft_printf(" %p ", 15);
	// ret = ft_printf(" %p ", 16);
	// ret = ft_printf(" %p ", 17);
	// ret = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	// ret = ft_printf(" %p %p ", INT_MIN, INT_MAX);
	// ret = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// ret = ft_printf(" %p %p ", 0, 0);
	// printf("\n\n%scategory: u%s \n", YELLOW, RESET);
	// ret_ft = ft_printf(" %u\n %u\n %u\n %u\n %u\n %u\n %u\n", \
	// 	INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
*/
