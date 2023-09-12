/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:47:17 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/26 01:51:44 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static bool	map_set_flags(char *ptr, t_u32 *flags, int *x, int *y)
{
	if (*ptr == 'P')
		*flags |= MAP_HAS_PLAYER;
	else if (*ptr == 'E')
		*flags |= MAP_HAS_EXIT;
	else if (*ptr == 'C')
		*flags |= MAP_HAS_COLLECT;
	else if (*ptr == '\n')
	{
		if (*(ptr - 1) != '1')
			return (false);
		*x = -1;
		*y += 1;
	}
	return (true);
}

bool	map_validate(t_map *map)
{
	char	*ptr;
	t_u32	flags;
	int		x;
	int		y;

	if (!(map && map_get_size(map, &map->w, &map->h)))
		return (false);
	ptr = map->data;
	x = 0;
	y = 0;
	flags = 0U;
	while (*ptr != '\0')
	{
		if (!ft_strchr("10PEC\n", *ptr)
			|| (*ptr == 'P' && flags & MAP_HAS_PLAYER)
			|| (x == 0 && *ptr != '1')
			|| ((y == map->h - 1) && (*ptr != '1' && *ptr != '\n'))
			|| !map_set_flags(ptr++, &flags, &x, &y))
			return (false);
		++x;
	}
	return ((flags & 7) == 7);
}
