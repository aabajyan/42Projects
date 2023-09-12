/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:07:47 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 17:08:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static const char	*ft_print(t_printf *data, const char *format)
{
	if (*format == 's')
		ft_out_str(data, va_arg(data->args, char*));
	else if (*format == 'c')
		ft_out_char(data, va_arg(data->args, int));
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		ft_out_digit(data, *format, va_arg(data->args, int));
	else if (*format == 'x' || *format == 'X')
		ft_out_hex(data, *format, va_arg(data->args, uint32_t));
	else if (*format == 'p')
		ft_out_pointer(data, (uintptr_t)va_arg(data->args, void*));
	else if (*format == 'o')
		ft_out_octal(data, va_arg(data->args, int));
	else if (*format == 'n')
		*va_arg(data->args, int*) = data->length;
	else
	{
		if (data->flags & FLAG_RIGHT)
			data->flags &= ~FLAG_ZEROPAD;
		ft_out_char(data, *format);
	}
	return (++format);
}

int					ft_snprintf(const char *format, va_list args)
{
	t_printf data;

	data.length = 0U;
	va_copy(data.args, args);
	while (format && *format)
	{
		data.width = 0U;
		data.precision = 0U;
		data.flags = 0U;
		if (*format != '%')
		{
			ft_putchar_fd(*format++, 1);
			++data.length;
			continue;
		}
		format = ft_parse_flags(&data, ++format);
		format = ft_parse_width(&data, format);
		format = ft_parse_precision(&data, format);
		format = ft_print(&data, format);
	}
	return (data.length);
}

int					ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_snprintf(format, args);
	va_end(args);
	return (result);
}
