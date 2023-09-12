/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:02:37 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 18:21:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_add_sign(t_printf *data, char *str)
{
	char sign;

	sign = 0;
	if (data->flags & FLAG_NEGATIVE)
		sign = '-';
	else if (data->flags & FLAG_PLUSSIGN)
		sign = '+';
	if (sign)
		data->flags &= ~FLAG_SPACE;
	if (sign && !(data->flags & FLAG_ZEROPAD))
		*--str = sign;
	else if (sign && data->flags & FLAG_ZEROPAD)
	{
		ft_putchar_fd(sign, 1);
		++data->length;
		--data->width;
	}
	return (str);
}

void		ft_out_digit(t_printf *data, char ch, int digit)
{
	char	*str;
	char	*ptr;
	int		len;

	if (ch == 'u')
		data->flags |= FLAG_UNSIGNED;
	if (!digit)
		data->flags &= ~FLAG_HASH;
	if (data->flags & FLAG_WIDTH)
		data->flags &= ~FLAG_ZEROPAD;
	str = ft_itoa_int(data, digit, 10);
	ptr = str;
	len = ft_strlen(str);
	str = ft_handle_precision(data, str);
	str = ft_add_sign(data, str);
	if (digit >= 0 && data->flags & FLAG_SPACE)
	{
		ft_putchar_fd(' ', 1);
		--data->width;
		++data->length;
	}
	data->flags &= ~FLAG_WIDTH;
	ft_out_str(data, str);
	if (ptr)
		free(ptr);
}
