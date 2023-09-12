/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:38:26 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/14 16:28:18 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t src_len;
	size_t dst_len;
	size_t max_len;

	src_len = ft_strlen(src);
	dst_len = 0;
	max_len = n;
	while (*dst && n--)
	{
		++dst;
		++dst_len;
	}
	if (max_len == dst_len)
		return (max_len + src_len);
	while (*src && --n)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
