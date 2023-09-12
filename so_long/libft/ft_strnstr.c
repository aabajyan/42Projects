/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:00:38 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 15:28:26 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t slen)
{
	size_t	len;

	if (!*find)
		return ((char *)str);
	len = ft_strlen(find);
	while (*str && slen-- >= len)
		if (ft_strncmp(find, str++, len) == 0)
			return ((char *)str - 1);
	return (NULL);
}
