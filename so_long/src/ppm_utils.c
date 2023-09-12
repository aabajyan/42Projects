/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:11:28 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/26 01:40:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_ppm	*ppm_destory_with_buffer(t_ppm *ppm, char *str)
{
	free(str);
	return (ppm_destroy(ppm));
}

bool	ppm_get_value(char **dptr, t_u8 *v)
{
	char	*ptr;

	ptr = *dptr;
	*v = 0;
	while (ft_isspace(*ptr))
		++ptr;
	if (*ptr == '\0')
		return (false);
	while (ft_isdigit(*ptr))
		*v = (*v * 10) + (*ptr++ - '0');
	*dptr = ptr;
	return (*ptr != '\0');
}

char	*ppm_get_size(char *ptr, int *v)
{
	while (ft_isdigit(*++ptr))
		*v = (*v * 10) + (*ptr - '0');
	return (ptr);
}
