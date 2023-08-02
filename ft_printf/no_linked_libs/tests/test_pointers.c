/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pointers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:30:19 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/02 11:48:30 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "test.h"

static void	test1(void);
static void	test2(void);

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
	aux = ret_ft;
	ft_printf(" ft_printf:\t");
	ret_ft = ft_printf("%p", &aux);
	printf("\treturn: %i\n", ret_ft);
	printf(" printf:\t");
	ret_st = printf("%p", &aux);
	printf("\treturn: %i\n", ret_st);
	printf("%sTest 2 result: %s", YELLOW, RESET);
	print_result(ret_ft == ret_st);
}
