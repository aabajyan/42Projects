/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:35:43 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/16 14:42:45 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strndup(const char *s, size_t len)
{
	char	*ptr;

	++len;
	if (!(ptr = (char*)malloc(len * sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	if (!(s1 && set))
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strrchr(set, s1[len - 1]))
		--len;
	while (*s1 && ft_strrchr(set, *s1))
	{
		++s1;
		--len;
	}
	if (len <= 0)
		len = 0;
	return (ft_strndup(s1, len));
}
