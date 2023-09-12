/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:54:23 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 15:28:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*buffer;

	if (!(s && f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s, len);
	while (i < len)
	{
		buffer[i] = f(i, buffer[i]);
		++i;
	}
	buffer[len] = '\0';
	return (buffer);
}
