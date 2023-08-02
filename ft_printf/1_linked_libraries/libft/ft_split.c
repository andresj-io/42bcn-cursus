/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:09:01 by andresj           #+#    #+#             */
/*   Updated: 2023/08/01 09:34:01 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char			**ft_split(char const *s, char c);
static int		count_words(char const *s, char c);
static t_status	split(char const *str, char c, char **splitted);
static t_status	add_word(char const *str, int len, char **words, int index);

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**splitted;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	splitted = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (!splitted)
		return (NULL);
	if (split(s, c, splitted) == err)
		return (NULL);
	splitted[word_count] = NULL;
	return (splitted);
}

static int	count_words(const char *s, char c)
{
	bool	is_word;
	int		count;
	int		i;

	is_word = false;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_word = false;
		else if (!is_word)
		{
			is_word = true;
			count++;
		}
		i++;
	}
	return (count);
}

static t_status	split(const char *str, char c, char **splitted)
{
	int	i;
	int	count;
	int	w_len;
	int	s_len;

	i = 0;
	count = 0;
	s_len = ft_strlen(str);
	while (i < s_len)
	{
		if (*(str + i) != c)
		{
			w_len = 0;
			while (*(str + i) != c && *(str + i) != '\0')
			{
				w_len++;
				i++;
			}
			if (add_word(str + i - w_len, w_len, splitted, count) == err)
				return (err);
			count++;
		}
		i++;
	}
	return (ok);
}

static t_status	add_word(char const *str, int len, char **words, int index)
{
	int		i;

	words[index] = (char *)malloc(sizeof(char) * (len + 1));
	if (!words[index])
	{
		i = 0;
		while (i < index)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (err);
	}
	ft_strlcpy(words[index], str, len + 1);
	return (ok);
}
