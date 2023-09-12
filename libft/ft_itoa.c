/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:12:48 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/14 12:46:19 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char			buffer[sizeof(int) * CHAR_BIT / 3 + 3];
	char			*str;
	unsigned int	i;

	str = buffer + sizeof(buffer);
	i = (unsigned)n;
	if (n < 0)
		i = -i;
	*--str = '\0';
	while (i > 9)
	{
		*--str = (i % 10) + '0';
		i /= 10;
	}
	*--str = i + '0';
	if (n < 0)
		*--str = '-';
	return (ft_strdup(str));
}
