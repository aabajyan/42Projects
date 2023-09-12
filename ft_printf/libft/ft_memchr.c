/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:30:48 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/07 15:29:41 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	register const char	*p;
	size_t				len;

	p = ptr;
	len = 0;
	while (len < num)
	{
		if (p[len] == value)
			return ((void*)(ptr + len));
		++len;
	}
	return (NULL);
}
