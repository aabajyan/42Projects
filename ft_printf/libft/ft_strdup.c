/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:40:59 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 18:25:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!(ptr = (char*)malloc(len * sizeof(char))))
		return (NULL);
	if (s)
		ft_memcpy(ptr, s, len);
	else
		*ptr = 0;
	return (ptr);
}
