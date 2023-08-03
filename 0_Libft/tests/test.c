/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:36 by andresj           #+#    #+#             */
/*   Updated: 2023/07/17 10:34:57 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <strings.h>
#include <ctype.h>
#include "list_utils.h"

void	test_atoi(void);
void	test_bzero(void);
void	test_isalpha(void);
void	test_split(void);
void	test_putnbr_fd(void);
void	test_lstclear(void);
void	test_lstmap(void);
void	*ft_strupper(void *str);

int	main(void)
{
	int		i = 0;
	void	(*tests[])(void) = {test_atoi,\
	test_bzero,\
	test_isalpha,\
	test_split,\
	test_putnbr_fd,\
	test_lstclear,\
	test_lstmap};
	
	while (tests[i])
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

void	lstdelone_f(void *content)
{
	if (!content)
		return ;
	free(content);
}

void	test_lstclear()
{
	t_list *l = ft_lstnew(ft_strdup("nyancat"));

	return ;
 	l->next = ft_lstnew(ft_strdup("#TEST#"));
 	ft_lstclear(&l, lstdelone_f);
 	write(2, "", 1);
 	if (!l)
 		exit(0);// success
 	exit(1); // error
}
int test_single_lstmap(int test_number, t_list **initial, t_list **expected);
void	test_lstmap()
{
	t_list *l = ft_lstnew(ft_strdup("nyancat"));
	t_list *new;
	
	int	res = test_single_lstmap(2, create_list(1, "hello!"), create_list(1, "__6"));
	if (res == 1)
		return ;
 	l->next = ft_lstnew(ft_strdup("#test#"));
 	new = ft_lstmap(l, ft_strupper, lstdelone_f);
}

void	*ft_strupper(void *str)
{
	char	*upper;
	
	upper = ft_strdup((char *)str);
	if (!upper)
		return (NULL);
	while (*upper)
	{
		*upper = ft_toupper(*upper);
		upper++;
	}
	return(upper);
}


void *map_length(void *s)
{
	char *str = malloc(30);
	if (str != NULL)
		sprintf(str, "__%lX", strlen((char *)s));
	return str;
}

void delete(void *content)
{
	char *str = (char *)content;
	if (str == NULL)
		return;
	if (str[0] != '_' || str[1] != '_')
		error("You are not using the " BMAG "del" NC " function correctly\n");
	free(content);
}

int test_single_lstmap(int test_number, t_list **initial, t_list **expected)
{
	char *list_str = list_to_str(initial);
	set_signature_tn(test_number, "ft_lstmap(%s, [s => __strlen(s)], [x => free(x)])", list_str); free(list_str);

	t_list *res = ft_lstmap(*initial, map_length, delete);
	int result = same_list(expected, &res);
	lstclear(&res, free);
	result = check_leaks(NULL) && result;

// #ifdef STRICT_MEM
	reset_malloc_mock();
	ft_lstmap(*initial, map_length, delete);
	int malloc_calls = reset_malloc_mock();
	int no_leaks;
	for (int i = 0; i < malloc_calls; i++)
	{
		sprintf(signature + g_offset, NC " NULL check for %ith malloc", i);
		malloc_set_null(i);
		t_list *res = ft_lstmap(*initial, map_length, delete);
		lstclear(&res, delete);
		no_leaks = check_leaks(NULL);
		if (!no_leaks) {
			fseek(errors_file, -1, SEEK_CUR);
			fprintf(errors_file, "Most likely you are not calling " BMAG "del" NC \
					" on the content when a new list node allocation fails.\n\n");
		}
		result = no_leaks && result;
		if (res != NULL)
			result = error("Should return NULL\n");
	}
// #endif
	return result;
}
