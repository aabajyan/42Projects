/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:39:50 by aabajyan          #+#    #+#             */
/*   Updated: 2021/02/14 12:46:09 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
	ft_putstr_fd(str, fd);
}
