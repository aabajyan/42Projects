/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:06:42 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 17:55:30 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_out_str(t_printf *data, char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (data->flags & FLAG_WIDTH && data->precision < len)
		data->pad = data->width - data->precision;
	else
		data->pad = data->width - len;
	ft_apply_width(data, false);
	while (*str)
	{
		if (data->flags & FLAG_WIDTH && !data->precision--)
			break ;
		ft_putchar_fd(*str++, 1);
		--data->width;
		++data->length;
	}
	ft_apply_width(data, true);
}
