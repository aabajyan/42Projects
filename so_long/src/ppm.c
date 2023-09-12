/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:58:23 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 15:51:43 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_ppm	*ppm_load_from_image(const char *file)
{
	t_ppm	*ppm;

	ppm = malloc(sizeof(t_ppm));
	if (!ppm)
		return (NULL);
	ppm->width = 0;
	ppm->height = 0;
	ppm->max = 0;
	ppm->pixel_count = 0;
	return (ppm_read(ppm, file));
}

t_ppm	*ppm_destroy(t_ppm *ppm)
{
	if (ppm && ppm->pixels)
		free(ppm->pixels);
	if (ppm)
		free(ppm);
	return (NULL);
}
