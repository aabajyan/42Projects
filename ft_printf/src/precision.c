/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:06:56 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 16:03:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

char	*ft_handle_precision(t_printf *data, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (data->precision < len)
		data->precision = len;
	if (data->flags & FLAG_WIDTH && data->precision >= len)
		data->flags &= ~FLAG_ZEROPAD;
	while (data->precision > len)
	{
		*--str = '0';
		--data->precision;
	}
	return (str);
}
