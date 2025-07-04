/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:55:14 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/09 11:49:10 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *s, char delimeter)
{
	size_t	count;
	int		find_word;

	count = 0;
	while (*s)
	{
		find_word = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			if (!find_word)
			{
			count++;
			find_word = 1;
			}
			s++;
		}
	}
	return (count);
}

static int	safe_malloc(char **words_arr, int pos, size_t buffer)
{
	int	i;

	i = 0;
	words_arr[pos] = malloc(buffer);
	if (!words_arr[pos])
	{
		while (i < pos)
		{
			free(words_arr[i]);
			i++;
		}
		free(words_arr);
		return (1);
	}
	return (0);
}

static int	fill_word_arr(char **words_arr, char const *s, char delimeter)
{
	int		i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			word_len++;
			s++;
		}
		if (word_len)
		{
			if (safe_malloc(words_arr, i, word_len + 1))
				return (1);
			ft_strlcpy(words_arr[i], s - word_len, word_len + 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**words_arr;

	if (!s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	words_arr = malloc(sizeof(char *) * (words + 1));
	if (!words_arr)
		return (NULL);
	words_arr[words] = NULL;
	if (fill_word_arr(words_arr, s, c))
		return (NULL);
	return (words_arr);
}
