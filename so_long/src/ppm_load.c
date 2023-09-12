/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:01:37 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 15:51:29 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_ppm	*ppm_read_content(t_ppm *ppm, char *image, char *ptr)
{
	t_u32	*pixel_ptr;
	t_u8	r;
	t_u8	g;
	t_u8	b;

	pixel_ptr = ppm->pixels;
	while (*++ptr != '\0')
	{
		if (!ppm_get_value(&ptr, &r))
			break ;
		if (!ppm_get_value(&ptr, &g))
			break ;
		if (!ppm_get_value(&ptr, &b))
			break ;
		pixel_ptr[ppm->pixel_count++] = rgba(r, g, b, 0);
	}
	free(image);
	return (ppm);
}

t_ppm	*ppm_read(t_ppm *ppm, const char *file)
{
	char	*image;
	char	*ptr;

	image = ft_readfile(file);
	if (!image)
		return (ppm_destroy(ppm));
	ptr = image;
	if (!(*ptr++ == 'P' && *ptr++ == '3'))
		return (ppm_destory_with_buffer(ppm, image));
	ptr = ppm_get_size(ptr, &ppm->width);
	ptr = ppm_get_size(ptr, &ppm->height);
	ptr = ppm_get_size(ptr, &ppm->max);
	ppm->pixels = malloc(sizeof(t_u32) * ppm->width * ppm->height);
	if (!ppm->pixels)
		return (ppm_destory_with_buffer(ppm, image));
	return (ppm_read_content(ppm, image, ptr));
}
