/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:42:55 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/19 19:06:00 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_handle_space(t_printf *data)
{
	if (data->flags & FLAG_SPACE)
	{
		ft_putchar_fd(' ', 1);
		--data->width;
	}
}
