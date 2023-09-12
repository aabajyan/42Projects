/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:12:21 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/14 13:37:46 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			result = (char*)&str[i];
		++i;
	}
	if (c == '\0' && result == NULL)
		return (char*)&str[i];
	return (result);
}
