/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:10:53 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 15:52:17 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include <stdint.h>

typedef int8_t		t_s8;
typedef uint8_t		t_u8;
typedef int16_t		t_s16;
typedef uint16_t	t_u16;
typedef int32_t		t_s32;
typedef uint32_t	t_u32;
typedef int64_t		t_s64;
typedef uint64_t	t_u64;

typedef uint32_t	t_color;
typedef void		t_mlx;
typedef void		t_mlx_window;

typedef struct s_ppm {
	int		width;
	int		height;
	int		max;
	t_u32	*pixels;
	t_u32	pixel_count;
}				t_ppm;

typedef struct s_mlx_image {
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_image;

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
}				t_rect;

typedef struct s_mlx_data {
	t_mlx			*mlx;
	t_mlx_window	*window;
	t_mlx_image		canvas;
	t_u32			flags;
	t_rect			size;
}				t_mlx_data;

#endif /* TYPES_H */
