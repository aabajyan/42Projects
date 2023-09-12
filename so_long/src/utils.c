/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:27:07 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/26 01:41:03 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_strappend(char *s1, char const *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2) + 1;
	ptr = malloc((s1len + s2len) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	if (s1 != NULL)
		free(s1);
	return (ptr);
}

char	*ft_readfile(const char *file)
{
	char	*result;
	char	*buffer;
	int		fd;
	int		size;

	buffer = malloc(sizeof(char) * 512 + 1);
	result = NULL;
	if (!buffer)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	size = read(fd, buffer, 512);
	while (size > 0)
	{
		buffer[size] = '\0';
		result = ft_strappend(result, buffer);
		size = read(fd, buffer, 512);
	}
	free(buffer);
	close(fd);
	return (result);
}

bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

bool	ft_endswith(const char *str, const char *suffix)
{
	size_t	len;
	size_t	slen;

	if (!str || !suffix)
		return (false);
	len = ft_strlen(str);
	slen = ft_strlen(suffix);
	if (slen > len)
		return (false);
	return (ft_strncmp(str + len - slen, suffix, slen) == 0);
}
