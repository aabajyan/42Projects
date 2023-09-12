/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:39:53 by aabajyan          #+#    #+#             */
/*   Updated: 2021/05/04 16:22:11 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_save(char *saved)
{
	char	*result;
	int		start;
	int		j;

	if (!saved)
		return (NULL);
	start = 0;
	j = 0;
	while (saved[start] && saved[start] != '\n')
		++start;
	if (!saved[start])
	{
		free(saved);
		return (NULL);
	}
	if (!(result = malloc(sizeof(char) * (ft_strlen(saved) - start++) + 1)))
		return (NULL);
	while (saved[start])
		result[j++] = saved[start++];
	result[j] = '\0';
	free(saved);
	return (result);
}

static char	*get_line(char *saved)
{
	char	*line;
	int		start;

	if (!saved)
		return (0);
	start = 0;
	while (saved[start] && saved[start] != '\n')
		++start;
	if (!(line = malloc(sizeof(char) * ++start)))
		return (0);
	start = 0;
	while (saved[start] && saved[start] != '\n')
	{
		line[start] = saved[start];
		++start;
	}
	line[start] = '\0';
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char *saved;
	char		*buffer;
	int			file_read;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	file_read = 1;
	while (!ft_strchr(saved, '\n') && file_read)
	{
		if ((file_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[file_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	*line = get_line(saved);
	saved = get_save(saved);
	return ((bool)file_read);
}
