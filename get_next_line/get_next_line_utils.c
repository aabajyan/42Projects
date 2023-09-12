/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:40:05 by aabajyan          #+#    #+#             */
/*   Updated: 2021/04/27 16:42:15 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_memcpy(char *dest, const char *src, size_t num)
{
	char	*d;

	if (!((d = dest) && src))
		return (NULL);
	while (num--)
		*d++ = *src++;
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	while (str && *str)
	{
		if (*str == c)
			return ((char*)str);
		++str;
	}
	if (str && c == '\0')
		return ((char*)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) + 1;
	if (!(ptr = (char*)malloc((s1len + s2len) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!(ptr = (char*)malloc(len * sizeof(char))))
		return (NULL);
	*ptr = 0;
	if (s)
		ft_memcpy(ptr, s, len);
	return (ptr);
}
