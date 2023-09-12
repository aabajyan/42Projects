/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:21:34 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/07 13:16:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	register unsigned char			*to;
	register const unsigned char	*from;
	int								i;

	to = (unsigned char*)dest;
	from = (const unsigned char*)src;
	i = n - 1;
	if (to == from || n == 0)
		return (dest);
	if (to > from && to - from < (int)n)
	{
		while (i >= 0)
		{
			to[i] = from[i];
			--i;
		}
		return (dest);
	}
	if (from > to && from - to < (int)n)
	{
		while (n--)
			*to++ = *from++;
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
