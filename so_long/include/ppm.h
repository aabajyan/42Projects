/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:20:41 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 15:52:27 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPM_H
# define PPM_H

t_ppm	*ppm_destory_with_buffer(t_ppm *ppm, char *str);
bool	ppm_get_value(char **dptr, t_u8 *v);
char	*ppm_get_size(char *ptr, int *v);

t_ppm	*ppm_load_from_image(const char *file);
t_ppm	*ppm_read(t_ppm *ppm, const char *file);
void	ppm_draw(t_mlx_data *g, t_ppm *ppm, t_vector tpos);
void	ppm_rect_draw(t_mlx_data *g, t_ppm *ppm, t_vector pos, t_rect rect);
t_ppm	*ppm_destroy(t_ppm *ppm);

#endif /* PPM_H */
