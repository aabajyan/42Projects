/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:07:42 by aabajyan          #+#    #+#             */
/*   Updated: 2021/04/08 17:04:45 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_handle_hex_width(t_printf *data, char *str, bool has_hash)
{
	int len;

	if (data->flags & FLAG_RIGHT || !(data->flags & FLAG_ZEROPAD))
		return (str);
	if (!(data->flags & FLAG_PAD))
		return (str);
	len = ft_strlen(str);
	data->pad = data->width - len;
	if (has_hash)
		data->pad -= 2;
	while (data->pad-- > 0)
		*--str = '0';
	data->flags &= ~FLAG_PAD;
	return (str);
}

void		ft_out_hex(t_printf *data, int ch, uint32_t n)
{
	char	h;
	char	*str;
	char	*ptr;

	data->flags |= FLAG_UNSIGNED;
	if (ch == 'x')
		h = 'a';
	else
		h = 'A';
	str = ft_itoa_base(n, 16, h);
	ptr = str;
	if (n == 0 && data->precision == 0 && data->flags & FLAG_WIDTH)
		++str;
	str = ft_handle_precision(data, str);
	str = ft_handle_hex_width(data, str, (n != 0 && data->flags & FLAG_HASH));
	if (n != 0 && data->flags & FLAG_HASH)
	{
		if (h == 'a')
			*--str = 'x';
		else
			*--str = 'X';
		*--str = '0';
	}
	data->flags -= data->flags & FLAG_WIDTH;
	ft_out_str(data, str);
}
