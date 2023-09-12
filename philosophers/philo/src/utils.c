/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:47:41 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 18:18:44 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	ft_atoll(const char *str)
{
	int64_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

int	error(const char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
		++i;
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, msg, i);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

uint64_t	timestamp(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((uint64_t)(temp.tv_sec * 1000 + temp.tv_usec / 1000));
}

bool	load_arg(int64_t *dest, char *arg)
{
	*dest = ft_atoll((const char *)arg);
	return ((*dest) < INT_MAX && (*dest) > INT_MIN && (*dest) >= 1);
}

void	print(t_philo *philo, const char *action)
{
	pthread_mutex_lock(&philo->ctx->printing);
	if (philo->ctx->end_sim == false)
		printf("%llu %d %s\n",
			timestamp() - philo->ctx->start, philo->id, action);
	pthread_mutex_unlock(&philo->ctx->printing);
}
