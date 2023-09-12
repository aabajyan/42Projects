/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:31:59 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/22 17:31:59 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
int	main(int argc, char **argv)
{
	t_mlx_data	g;

	on_init(&g, argc, argv);
	mlx_loop_hook(g.mlx, on_loop, &g);
	mlx_hook(g.window, E_KEY_RELEASE, M_KEY_RELEASE, on_release, &g);
	mlx_hook(g.window, E_DESTROY_NOTIFY, 0, on_close, &g);
	mlx_loop(g.mlx);
	return (0);
}
