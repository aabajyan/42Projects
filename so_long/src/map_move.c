/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:48:34 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/26 01:42:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_vector	map_find_player(t_map *map)
{
	t_vector	pos;
	char		*ptr;

	pos = (t_vector){0};
	ptr = map->data;
	while (*ptr != '\0')
	{
		if (*ptr == 'P')
		{
			*ptr = '0';
			return (pos);
		}
		else if (*ptr == '\n')
		{
			pos.x = -1;
			++pos.y;
		}
		++ptr;
		++pos.x;
	}
	return (pos);
}

int	map_collect_count(t_map *map)
{
	char	*ptr;
	int		count;

	ptr = map->data;
	count = 0;
	while (*ptr != '\0')
		if (*ptr++ == 'C')
			++count;
	return (count);
}

void	map_move(t_map *map, int kc)
{
	t_vector	pos;
	t_vector	new_pos;

	pos = map_find_player(map);
	new_pos = pos;
	if (kc == KEY_W || kc == KEY_S || kc == KEY_A || kc == KEY_D)
		map->moves++;
	if (kc == KEY_W)
		new_pos.y--;
	else if (kc == KEY_S)
		new_pos.y++;
	else if (kc == KEY_A)
		new_pos.x--;
	else if (kc == KEY_D)
		new_pos.x++;
	if (map->data[new_pos.y * (map->w + 1) + new_pos.x] == '1')
		new_pos = pos;
	else if (map->data[new_pos.y * (map->w + 1) + new_pos.x] == 'E')
	{
		if (map_collect_count(map) > 0)
			new_pos = pos;
		else
			map->done = true;
	}
	map->data[new_pos.y * (map->w + 1) + new_pos.x] = 'P';
}
