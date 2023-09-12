/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:47:30 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 15:44:00 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		ft_out_char(t_printf *data, int ch)
{
	data->pad = data->width - 1;
	ft_apply_width(data, false);
	ft_putchar_fd((char)ch, 1);
	++data->length;
	ft_apply_width(data, true);
}
