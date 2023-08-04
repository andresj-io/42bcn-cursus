/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:58:07 by andresj           #+#    #+#             */
/*   Updated: 2023/08/04 15:58:28 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_strings(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}

char	*dup_str(const char *s1)
{
	int		len1;
	char	*new;

	len1 = 0;
	while (*s1)
		len1++;
	new = (char *) malloc(sizeof(char) * (len1 + 1));
	if (!new)
		return (NULL);
	len1 = -1;
	while (*(s1 + ++len1))
		*(new + len1) = *(s1 + len1);
	return (new);
}

void	str_copy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + ++i) = '\0';
}

void	str_append(t_string *dst, const char *src, int from, int to)
{
	while (from < to)
	{
		*(dst->str + dst->ix) = *(src + from);
		from++;
		dst->ix++;
	}
}

char	*concat_str(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*concat;

	len1 = 0;
	len2 = 0;
	while (*s1)
		len1++;
	while (*s2)
		len2++;
	concat = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!concat)
		return (NULL);
	len1 = -1;
	while (*(s1 + ++len1))
		*(concat + len1) = *(s1 + len1);
	len2 = -1;
	while (*(s2 + ++len2))
		*(concat + len1 + len2) = *(s1 + len2);
	return (concat);
}
