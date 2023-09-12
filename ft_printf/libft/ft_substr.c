/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:11:19 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/16 14:43:00 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s || !(ptr = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start >= ft_strlen(s))
		return (ptr);
	ft_memcpy(ptr, s + start, len);
	if (*(ptr + len) != '\0')
		*(ptr + len) = '\0';
	return (ptr);
}
