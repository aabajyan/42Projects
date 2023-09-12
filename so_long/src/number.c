/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:15:25 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/26 02:00:04 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_mlx_data	*g_data;
t_ppm		*g_nbr_img;

void	number_init(t_mlx_data *g)
{
	g_data = g;
	g_nbr_img = ppm_load_from_image("./resources/number.ppm");
}

void	number_draw(int number, t_vector pos)
{
	char		*str;
	int			n;
	int			i;
	t_vector	new_pos;
	t_rect		rect;

	str = ft_itoa(number);
	i = 0;
	new_pos = pos;
	rect = (t_rect){0, 0, 32, 32};
	while (str[i] != '\0')
	{
		n = str[i++] - '0';
		if (n < 0 || n > 9)
			continue ;
		new_pos.x = pos.x + (i * 32);
		rect.x = n * 32;
		ppm_rect_draw(g_data, g_nbr_img, new_pos, rect);
	}
	free(str);
}

void	number_deinit(void)
{
	ppm_destroy(g_nbr_img);
}
