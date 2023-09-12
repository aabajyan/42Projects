/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:07:18 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 18:02:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	ft_out_octal(t_printf *data, int n)
{
	char	*str;
	char	*ptr;
	int		len;

	data->flags |= FLAG_UNSIGNED;
	str = ft_itoa_base(n, 8, 'a');
	ptr = str;
	str = ft_handle_precision(data, str);
	len = ft_strlen(str);
	data->flags -= data->flags & FLAG_WIDTH;
	if (data->flags & FLAG_HASH && len <= data->precision)
	{
		*--str = '0';
		--data->precision;
	}
	ft_out_str(data, str);
	if (ptr)
		free(ptr);
}
