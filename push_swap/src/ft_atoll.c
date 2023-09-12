/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:11:23 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 12:14:29 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <limits.h>

bool	sort_check_limit(const char *str)
{
	long long	result;

	result = ft_atoll(str);
	return (result > INT_MAX || result < INT_MIN);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0l;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}
