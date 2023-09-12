/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:13:45 by aabajyan          #+#    #+#             */
/*   Updated: 2021/04/08 17:05:10 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_apply_width(t_printf *data, bool has_right)
{
	char	pad;
	int		width;

	if (!(data->flags & FLAG_PAD))
		return ;
	pad = ' ';
	width = data->pad;
	if (data->flags & FLAG_ZEROPAD)
		pad = '0';
	if ((bool)(data->flags & FLAG_RIGHT) == has_right)
		while (width-- > 0)
		{
			ft_putchar_fd(pad, 1);
			++data->length;
		}
}
