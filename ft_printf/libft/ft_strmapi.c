/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:54:23 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/16 14:42:34 by aabajyan         ###   ########.fr       */
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
	if (!(buffer = (char*)malloc(sizeof(char) * (len + 1))))
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
