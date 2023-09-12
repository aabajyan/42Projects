/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:00:46 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/24 16:18:16 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ppm_draw(t_mlx_data *g, t_ppm *ppm, t_vector tpos)
{
	t_vector	pos;
	t_vector	real_pos;

	pos = (t_vector){0};
	real_pos = (t_vector){0};
	while (pos.y < ppm->height)
	{
		pos.x = 0;
		while (pos.x < ppm->width)
		{
			real_pos = (t_vector){pos.x + tpos.x, pos.y + tpos.y};
			pixel(g, real_pos, ppm->pixels[pos.y * ppm->width + pos.x]);
			++pos.x;
		}
		++pos.y;
	}
}

void	ppm_rect_draw(t_mlx_data *g, t_ppm *ppm, t_vector pos, t_rect rect)
{
	t_vector	real_pos;
	t_vector	rect_pos;
	int			i;
	t_u32		pixels;

	real_pos = (t_vector){0};
	rect_pos = (t_vector){0};
	i = 0;
	pixels = ppm->pixel_count;
	while (rect_pos.y < rect.height)
	{
		rect_pos.x = 0;
		while (rect_pos.x < rect.width)
		{
			i = (rect_pos.y + rect.y) * ppm->width + (rect_pos.x + rect.x);
			real_pos = (t_vector){rect_pos.x + pos.x, rect_pos.y + pos.y};
			pixel(g, real_pos, ppm->pixels[i]);
			if (pixels-- <= 0)
				return ;
			rect_pos.x++;
		}
		rect_pos.y++;
	}
}
