/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:44:27 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 15:32:34 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	bool	is_word;

	i = 0;
	is_word = false;
	while (*s)
	{
		if (!is_word && *s != c)
			is_word = ((bool)++i);
		else if (is_word && *s == c)
			is_word = false;
		++s;
	}
	return (i);
}

static void	*ft_freeall(char **arr, size_t index)
{
	while (index--)
		free(arr[index]);
	free(arr);
	return (NULL);
}

static size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	size_t	word_count;
	size_t	arr_len;
	char	**arr;

	if (!s)
		return (NULL);
	index = 0;
	arr_len = 0;
	word_count = ft_wordcount(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && word_count--)
	{
		while (*s && *s == c)
			++s;
		arr_len = ft_strclen(s, c);
		arr[index] = ft_substr(s, 0, arr_len);
		if (!arr[index++])
			return (ft_freeall(arr, index - 1));
		s += arr_len;
	}
	arr[index] = NULL;
	return (arr);
}
