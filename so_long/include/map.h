/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:53:32 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 01:53:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	int			tw;
	int			th;
	int			w;
	int			h;
	int			moves;
	bool		done;
	t_ppm		*t;
	char		*data;
}				t_map;

# define MAP_HAS_PLAYER 1
# define MAP_HAS_EXIT 2
# define MAP_HAS_COLLECT 4

t_map	*map_load(const char *path, t_ppm *tileset, int w, int h);
bool	map_get_size(t_map *map, int *w, int *h);
bool	map_validate(t_map *map);
void	map_draw(t_mlx_data *g, t_map *map);
void	map_move(t_map *map, int kc);
t_map	*map_destroy(t_map *map);

#endif /* MAP_H */
