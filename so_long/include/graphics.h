/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:14:10 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/15 01:14:10 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "common.h"

t_color	rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
void	pixel(t_mlx_data *g, t_vector pos, t_color c);
void	line(t_mlx_data *g, t_vector pos1, t_vector pos2, t_color c);
void	rect(t_mlx_data *g, t_rect rect, t_color c);
void	img(t_mlx_data *g, t_ppm *ppm, t_vector pos, t_rect rect);
void	do_sync(t_mlx_data *g);

#endif
