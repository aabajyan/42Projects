/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:56:58 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/22 16:56:58 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_color	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	pixel(t_mlx_data *g, t_vector pos, t_color c)
{
	char			*dest;
	unsigned int	ppos;

	if (pos.x < 0 || pos.y < 0
		|| pos.x >= g->size.width || pos.y >= g->size.height
		|| (((c >> 16) & 0xff) == 0xff
			&& (c & 0xff) == 0xff && ((c >> 8) & 0xff) == 0))
		return ;
	ppos = pos.y * g->canvas.line_length;
	ppos += pos.x * (g->canvas.bits_per_pixel / 8);
	dest = g->canvas.address + ppos;
	*(t_u32 *)dest = c;
}

void	line(t_mlx_data *g, t_vector pos1, t_vector pos2, t_color c)
{
	t_vector	dpos;
	t_vector	pos;

	dpos = (t_vector){pos2.x - pos1.x, pos2.y - pos1.y};
	pos = (t_vector){pos1.x, 0};
	while (pos.x <= pos2.x)
	{
		pos.y = pos1.y + dpos.y * (pos.x - pos1.x) / dpos.x;
		pixel(g, pos, c);
		++pos.x;
	}
}

void	rect(t_mlx_data *g, t_rect rect, t_color c)
{
	t_vector	pos1;
	t_vector	pos2;

	pos1 = (t_vector){rect.x, 0};
	pos2 = (t_vector){rect.x + rect.width, 0};
	while (rect.height-- > 0)
	{
		pos1.y = rect.y + rect.height;
		pos2.y = rect.y + rect.height;
		line(g, pos1, pos2, c);
	}
}

void	do_sync(t_mlx_data *g)
{
	mlx_put_image_to_window(g->mlx, g->window, g->canvas.image, 0, 0);
	mlx_do_sync(g->mlx);
}
