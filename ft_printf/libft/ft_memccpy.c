/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:20:33 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/07 13:24:09 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, const char c, size_t n)
{
	register unsigned char			*d;
	register const unsigned char	*s;
	register unsigned char			fc;

	if (n)
	{
		d = (unsigned char *)dest;
		s = (const unsigned char *)src;
		fc = (unsigned char)c;
		while (n != 0)
		{
			if ((*d++ = *s++) == fc)
				return (d);
			--n;
		}
	}
	return (0);
}
