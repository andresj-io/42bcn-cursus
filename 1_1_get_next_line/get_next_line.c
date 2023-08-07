/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:59:49 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/06 21:12:00 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_until(int fd, t_string *store, int *nl_ix);
static void	add_2_store(t_string *store, t_string *new);
static char	*parse(t_string *store, int nl_ix);
static void	set_left_over(t_string *store, int nl_ix);

char	*get_next_line(int fd)
{
	static t_string	store;
	int				nl_ix;
	char			*next;

	if (fd < 0 || ((size_t)BUFFER_SIZE <= 0))
		return (NULL);
	nl_ix = -1;
	if (store.ix)
		nl_ix = gnl_search_nl(store.s);
	read_until(fd, &store, &nl_ix);
	next = NULL;
	if (store.ix)
		next = parse(&store, nl_ix);
	if (!next)
		gnl_free(&store);
	return (next);
}

static void	read_until(int fd, t_string *store, int *nl_ix)
{
	t_string	b_read;
	char		buffer[BUFFER_SIZE + 1];

	b_read.s = buffer;
	b_read.ix = 1;
	while (*nl_ix == -1 && b_read.ix > 0)
	{
		b_read.ix = read(fd, b_read.s, (size_t)BUFFER_SIZE);
		if (b_read.ix > 0)
		{
			*(b_read.s + b_read.ix) = '\0';
			*nl_ix = gnl_search_nl(b_read.s) + store->ix;
			add_2_store(store, &b_read);
			if (!store->s)
				break ;
		}
	}
	if (b_read.ix == -1)
		gnl_free(store);
}

static void	add_2_store(t_string *store, t_string *new)
{
	t_string	aux;

	aux.ix = 0;
	aux.s = malloc(sizeof(char) * (store->ix + new->ix + 1));
	if (!aux.s)
	{
		gnl_free(store);
		return ;
	}
	if (store->ix)
		gnl_str_append(&aux, store, 0, store->ix);
	gnl_free(store);
	*store = aux;
	gnl_str_append(store, new, 0, new->ix);
}

static char	*parse(t_string *store, int nl_ix)
{
	t_string	next;

	next.s = NULL;
	next.ix = 0;
	if (nl_ix > 0 && *(store->s + store->ix + 1))
	{
		next.s = malloc(sizeof(char) * (nl_ix + 1));
		if (!next.s)
			return (NULL);
		gnl_str_append(&next, store, 0, nl_ix - 1);
		set_left_over(store, nl_ix);
		if (!store->s)
			gnl_free(&next);
	}
	else
	{
		next.s = malloc(sizeof(char) * (store->ix + 1));
		if (!next.s)
			return (NULL);
		gnl_str_append(&next, store, 0, store->ix);
		gnl_free(store);
	}
	return (next.s);
}

static void	set_left_over(t_string *store, int nl_ix)
{
	t_string	aux;

	aux.ix = 0;
	aux.s = malloc(sizeof(char) * (store->ix - nl_ix + 1));
	if (!aux.s)
	{
		gnl_free(store);
		return ;
	}
	gnl_str_append(&aux, store, nl_ix + 1, store->ix);
	*store = aux;
	gnl_free(&aux);
}
