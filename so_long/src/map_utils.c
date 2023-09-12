/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:57:13 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/24 14:34:27 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool	map_get_size(t_map *map, int *w, int *h)
{
	char	*ptr;
	int		x;

	ptr = map->data;
	x = 0;
	*w = 0;
	*h = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '\n')
		{
			if (x != *w)
				return (false);
			*h += 1;
			x = -1;
		}
		if (*h == 0)
			*w += 1;
		++x;
		++ptr;
	}
	return (true);
}
