/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:58:07 by andresj           #+#    #+#             */
/*   Updated: 2023/08/06 20:39:08 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Frees memory if string is not null and restores index to 0
*/
void	gnl_free(t_string *p)
{
	p->ix = 0;
	if (p->s)
	{
		free(p->s);
		p->s = NULL;
	}
}

/*
	Appends src string to dst using `from` index until `to` index
*/
void	gnl_str_append(t_string *dst, t_string *src, int from, int to)
{
	if (!src)
	{
		*(dst->s + ++dst->ix) = '\0';
		return ;
	}
	while (from < to)
	{
		*(dst->s + dst->ix) = *(src->s + from);
		dst->ix++;
		from++;
	}
	*(dst->s + dst->ix) = '\0';
}

int	gnl_search_nl(char *str)
{
	int	nl_ix;

	nl_ix = 0;
	if (!str || !*str)
		return (-1);
	while (*(str + nl_ix))
	{
		if (*(str + nl_ix) == '\n')
		{
			return (nl_ix);
		}
		nl_ix++;
	}
	return (-1);
}
