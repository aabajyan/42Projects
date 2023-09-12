/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:01:36 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 18:24:53 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cond_sleep(t_philo *philo, uint64_t ms)
{
	uint64_t	now;

	now = timestamp();
	while (philo->ctx->end_sim == false && timestamp() - now < ms)
		usleep(50);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	print(philo, FORK);
	print(philo, FORK);
	pthread_mutex_lock(&philo->ctx->check);
	philo->ate_at = timestamp();
	philo->ate_count++;
	print(philo, EATING);
	pthread_mutex_unlock(&philo->ctx->check);
	cond_sleep(philo, philo->ctx->time_to_eat);
}

void	*thread_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ctx->count == 1)
	{
		print(philo, FORK);
		return (NULL);
	}
	if (philo->id % 2)
		usleep(15000);
	while (philo->ctx->end_sim == false)
	{
		if (philo->ctx->eating_count != -1
			&& philo->ate_count >= philo->ctx->eating_count)
			break ;
		eating(philo);
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		print(philo, SLEEPING);
		cond_sleep(philo, philo->ctx->time_to_sleep);
		print(philo, THINKING);
	}
	return (NULL);
}
