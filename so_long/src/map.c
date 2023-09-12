/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:56:41 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 01:56:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_map	*map_load(const char *path, t_ppm *tileset, int w, int h)
{
	t_map	*map;

	if (!ft_endswith(path, ".ber"))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = ft_readfile(path);
	if (!map->data)
		return (map_destroy(map));
	map->t = tileset;
	map->tw = w;
	map->th = h;
	map->w = 0;
	map->h = 0;
	map->moves = 0;
	map->done = false;
	return (map);
}

static char	*map_update_pos(char *ptr, int *x, int *y)
{
	if (*ptr++ == '\n')
	{
		*y += 1;
		*x = -1;
	}
	*x += 1;
	return (ptr);
}

static t_rect	map_get_rect(t_map *map, int x, int y)
{
	return ((t_rect){x, y, map->tw, map->th});
}

void	map_draw(t_mlx_data *g, t_map *map)
{
	char		*ptr;
	int			x;
	int			y;
	t_vector	p;

	ptr = map->data;
	x = 0;
	y = 0;
	while (*ptr != '\0')
	{
		p = (t_vector){map->tw * x, map->th * y};
		if (*ptr == '1')
			ppm_rect_draw(g, map->t, p, map_get_rect(map, map->tw, 0));
		if (*ptr == 'P')
			ppm_rect_draw(g, map->t, p, map_get_rect(map, 0, 0));
		if (*ptr == 'E')
			ppm_rect_draw(g, map->t, p, map_get_rect(map, map->tw * 2, 0));
		if (*ptr == 'C')
			ppm_rect_draw(g, map->t, p, map_get_rect(map, map->tw * 3, 0));
		ptr = map_update_pos(ptr, &x, &y);
	}
}

t_map	*map_destroy(t_map *map)
{
	if (map && map->data)
		free(map->data);
	if (map)
		free(map);
	return (NULL);
}
