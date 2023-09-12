/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:08:33 by aabajyan          #+#    #+#             */
/*   Updated: 2021/04/08 16:55:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_ptoa(uintptr_t n)
{
	char		buffer[sizeof(uintptr_t) * CHAR_BIT];
	uint32_t	rem;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = buffer + sizeof(buffer);
	*--str = '\0';
	while (n)
	{
		rem = n % 16;
		if (rem > 9)
			*--str = (rem - 10) + 'a';
		else
			*--str = rem + '0';
		n /= 16;
	}
	return (ft_strndup(str, sizeof(buffer)));
}

void		ft_out_pointer(t_printf *data, uintptr_t ptr)
{
	char	*str;
	char	*str_ptr;

	data->flags |= FLAG_UNSIGNED;
	str = ft_ptoa(ptr);
	data->flags -= data->flags & FLAG_WIDTH;
	str = ft_handle_precision(data, str);
	str_ptr = str;
	*--str = 'x';
	*--str = '0';
	ft_out_str(data, str);
	if (str_ptr)
		free(str_ptr);
}
