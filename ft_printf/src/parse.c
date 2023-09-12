/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:07:00 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 17:40:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

const char	*ft_parse_flags(t_printf *data, const char *format)
{
	while (ft_strchr("-+0#lh ", *format))
	{
		if (*format == '-')
		{
			data->flags &= ~FLAG_ZEROPAD;
			data->flags |= FLAG_RIGHT;
		}
		else if (*format == '#')
			data->flags |= FLAG_HASH;
		else if (*format == ' ')
			data->flags |= FLAG_SPACE;
		else if (*format == '0')
			data->flags |= FLAG_ZEROPAD;
		else if (*format == '+')
		{
			data->flags &= FLAG_SPACE;
			data->flags |= FLAG_PLUSSIGN;
		}
		++format;
	}
	return (format);
}

const char	*ft_parse_width(t_printf *data, const char *format)
{
	if (ft_isdigit(*format))
		data->flags |= FLAG_PAD;
	while (ft_isdigit(*format))
		data->width = (data->width * 10) + (*format++ - '0');
	if (!data->width && *format == '*')
	{
		data->flags |= FLAG_PAD;
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->flags |= FLAG_RIGHT;
			data->flags &= ~FLAG_ZEROPAD;
			data->width = -data->width;
		}
		++format;
	}
	return (format);
}

const char	*ft_parse_precision(t_printf *data, const char *format)
{
	if (*format == '.')
	{
		data->flags |= FLAG_WIDTH;
		while (ft_isdigit(*++format))
			data->precision = (data->precision * 10) + (*format - '0');
		if (!data->precision && *format == '*')
		{
			data->precision = va_arg(data->args, int);
			if (data->precision < 0)
				data->flags &= ~FLAG_WIDTH;
			++format;
		}
	}
	return (format);
}
