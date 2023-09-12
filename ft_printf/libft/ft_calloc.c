/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:33:42 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/07 16:38:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t el_num, size_t el_size)
{
	void *ptr;

	if (el_num == 0 && el_size == 0)
	{
		el_num = 1;
		el_size = 1;
	}
	ptr = malloc(el_num * el_size);
	if (ptr)
		ft_bzero(ptr, el_num * el_size);
	return (ptr);
}
