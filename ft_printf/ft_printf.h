/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:28:56 by aabajyan          #+#    #+#             */
/*   Updated: 2021/03/25 17:20:25 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

# define FLAG_RIGHT 1
# define FLAG_ZEROPAD 2
# define FLAG_SPACE 4
# define FLAG_HASH 8
# define FLAG_WIDTH 16
# define FLAG_NEGATIVE 32
# define FLAG_UNSIGNED 64
# define FLAG_PLUSSIGN 128
# define FLAG_PAD 256

typedef struct	s_printf
{
	va_list		args;
	int			width;
	int			pad;
	int			length;
	int			precision;
	uint32_t	flags;
}				t_printf;

char			*ft_itoa_int(t_printf *data, int n, int base);
char			*ft_itoa_base(uint32_t n, uint8_t base, char hex);

const char		*ft_parse_flags(t_printf *data, const char *format);
const char		*ft_parse_width(t_printf *data, const char *format);
const char		*ft_parse_precision(t_printf *data, const char *format);

void			ft_handle_space(t_printf *data);
char			*ft_handle_precision(t_printf *data, char *str);
void			ft_out_digit(t_printf *data, char ch, int digit);
void			ft_out_float(t_printf *data, float digit);
void			ft_out_str(t_printf *data, char *str);
void			ft_out_char(t_printf *data, int ch);
void			ft_out_hex(t_printf *data, int ch, uint32_t n);
void			ft_out_pointer(t_printf *data, uintptr_t ptr);
void			ft_out_octal(t_printf *data, int n);

int				ft_snprintf(const char *format, va_list args);
int				ft_printf(const char *format, ...);
void			ft_apply_width(t_printf *data, bool has_right);

char			*ft_strndup(const char *s, size_t len);

#endif
