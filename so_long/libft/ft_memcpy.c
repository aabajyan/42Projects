/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:00:55 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 15:32:58 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	register char		*d;
	register const char	*s;

	if (dest == 0 && src == 0)
		return (0);
	d = (char *)dest;
	s = (const char *)src;
	while (num--)
		*d++ = *s++;
	return (dest);
}
