/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:07:38 by aabajyan          #+#    #+#             */
/*   Updated: 2021/04/08 17:01:27 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

char		*ft_strndup(const char *s, size_t len)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(len * sizeof(char))))
		return (NULL);
	if (s)
		ft_memcpy(ptr, s, len);
	return (ptr);
}

char		*ft_itoa_base(uint32_t n, uint8_t base, char hex)
{
	char		buffer[32U];
	uint32_t	rem;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = buffer + sizeof(buffer);
	*--str = '\0';
	while (n)
	{
		rem = n % base;
		if (rem > 9)
			*--str = (rem - 10) + hex;
		else
			*--str = rem + '0';
		n /= base;
	}
	return (ft_strndup(str, sizeof(buffer)));
}

char		*ft_itoa_int(t_printf *data, int n, int base)
{
	char		buffer[sizeof(int) * CHAR_BIT / 3 + 3];
	char		*str;
	int			rem;
	unsigned	i;

	if (n == 0 && data->precision == 0 && data->flags & FLAG_WIDTH)
		return (ft_strdup(""));
	else if (n == 0)
		return (ft_strdup("0"));
	str = buffer + sizeof(buffer);
	i = (unsigned)n;
	if (n < 0 && !(data->flags & FLAG_UNSIGNED))
		i = -i;
	*--str = '\0';
	while (i)
	{
		if ((rem = i % base) > 9)
			*--str = (rem - 10) + 'a';
		else
			*--str = rem + '0';
		i /= base;
	}
	if (n < 0 && !(data->flags & FLAG_UNSIGNED))
		data->flags |= FLAG_NEGATIVE;
	return (ft_strndup(str, sizeof(buffer)));
}
