/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:13:54 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 13:26:43 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	ret = ft_printf(" %p %p \n", NULL, NULL);
	ret = ft_printf(" %p\n", &ret);
	ret = printf(" %p\n", &ret);
	ret = ft_printf(" %u\n %u\n %u\n %u\n %u\n %u\n %u\n", \
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
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
*/
