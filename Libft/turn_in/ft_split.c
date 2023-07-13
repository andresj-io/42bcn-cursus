/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andresj <andresj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:09:01 by andresj           #+#    #+#             */
/*   Updated: 2023/07/11 07:06:53 by andresj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
int				static count_words(char const *s, char c);
t_status	static split(char const *str, char c, int wq, char **splitted);
t_status	static add_word(char const *str, int len, char **sp, int w_ix);

char	**ft_split(char const *s, char c)
{
	int		word_q;
	char	**splitted;

	if (!s)
		return (NULL);
	word_q = count_words(s, c);
	if (word_q == 0)
		return (NULL);
	splitted = (char **) malloc(sizeof(char *) * (word_q + 1));
	if (!splitted)
		return (NULL);
	if (split(s, c, word_q, splitted) == error)
		return (NULL);
	splitted[word_q] = NULL;
	return (splitted);
}

int		static count_words(const char *s, char c)
{
	bool	is_word;
	int		count;

	is_word = false;
	count = 0;
	while (*s)
	{
		if (*s == c)
			is_word = false;
		else if (!is_word)
		{
			is_word = true;
			count++;
		}
		s++;
	}
	return (++count);
}

t_status	static split(const char *str, char c, int wq, char **splitted)
{
	int		i;
	int		word_ix;
	int		wlen;

	i = 0;
	wlen = 0;
	word_ix = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c || str[i] != '\0')
			{
				wlen++;
				i++;
			}
			if (add_word(str - wlen, wlen, splitted, word_ix) == error)
				return (error);
			word_ix++;
		}
		i++;
	}
	return (ok);
}

t_status	static add_word(char const *str, int len, char **sp, int w_ix)
{
	int		i;
	
	sp[w_ix] = (char*)malloc(sizeof(char) * (len +1));
	if (!sp[w_ix])
	{
		i = 0;
		while (i < w_ix)
		{
			free(sp[i]);
			i++;
		}
		free(sp);
		return (error);
	}
	ft_strlcpy(sp[w_ix], str, len + 1);
	return (ok);
}