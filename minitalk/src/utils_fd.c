/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:27:20 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/10 18:51:20 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		write(fd, s++, 1);
}

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
