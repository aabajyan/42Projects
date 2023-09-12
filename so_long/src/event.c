/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:30:29 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 16:16:51 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

bool		g_should_close;
t_ppm		*g_image;
t_map		*g_map;

void	on_init(t_mlx_data	*g, int argc, char **argv)
{
	if (argc != 2)
		on_error("Error\nToo few arguments.\n");
	g_should_close = false;
	g_image = ppm_load_from_image("./resources/tileset.ppm");
	if (!g_image)
		on_error("Error\nFailed to load the image.\n");
	g_map = map_load(argv[1], g_image, 32, 32);
	if (!map_validate(g_map))
		on_error("Error\nCurrent map is invalid.\n");
	g->size = (t_rect){0, 0, g_map->w * g_map->tw, g_map->h * g_map->th};
	g->mlx = mlx_init();
	g->window = mlx_new_window(
			g->mlx, g->size.width, g->size.height, "So long");
	g->canvas.image = mlx_new_image(g->mlx, g->size.width, g->size.height);
	g->canvas.address = mlx_get_data_addr(
			g->canvas.image, &g->canvas.bits_per_pixel,
			&g->canvas.line_length, &g->canvas.endian);
	g->flags = 0U;
	number_init(g);
}

void	on_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	map_destroy(g_map);
	ppm_destroy(g_image);
	number_deinit();
	g_should_close = true;
	exit(1);
}

int	on_loop(t_mlx_data *g)
{
	if (g_map->done)
		on_close(g);
	rect(g, g->size, rgba(20, 20, 20, 0));
	map_draw(g, g_map);
	number_draw(g_map->moves, (t_vector){8, 32});
	do_sync(g);
	return (0);
}

int	on_close(t_mlx_data *g)
{
	mlx_destroy_window(g->mlx, g->window);
	map_destroy(g_map);
	ppm_destroy(g_image);
	number_deinit();
	g_should_close = true;
	exit(0);
	return (0);
}

int	on_release(int keycode, t_mlx_data *g)
{
	if (keycode == KEY_ESC)
		return (on_close(g));
	map_move(g_map, keycode);
	(void)g;
	return (0);
}
