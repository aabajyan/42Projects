/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:59:59 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/14 12:49:42 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t size)
{
	register char	*cb;
	unsigned int	i;

	cb = buffer;
	i = 0;
	while (i < size)
		cb[i++] = c;
	return (cb);
}
