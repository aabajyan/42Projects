/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:55:38 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 17:44:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_ctx *ctx)
{
	int				i;
	unsigned long	time;

	i = 0;
	time = timestamp();
	ctx->philos = malloc(sizeof(t_philo *) * ctx->count);
	while (i < ctx->count)
	{
		ctx->philos[i] = malloc(sizeof(t_philo));
		ctx->philos[i]->ctx = ctx;
		ctx->philos[i]->ate_at = time;
		ctx->philos[i]->id = i + 1;
		ctx->philos[i]->ate_count = 0;
		ctx->philos[i]->thread = malloc(sizeof(pthread_t));
		ctx->philos[i]->left = ctx->forks[i];
		ctx->philos[i]->right = ctx->forks[(i + 1) % ctx->count];
		pthread_create(
			ctx->philos[i]->thread, NULL,
			&thread_philo, (void *)ctx->philos[i]);
		++i;
	}
}

void	init_forks(t_ctx *ctx)
{
	int	i;

	i = 0;
	ctx->forks = malloc(sizeof(pthread_mutex_t *) * ctx->count);
	while (i < ctx->count)
	{
		ctx->forks[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(ctx->forks[i++], NULL);
	}
	pthread_mutex_init(&ctx->check, NULL);
	pthread_mutex_init(&ctx->printing, NULL);
}
