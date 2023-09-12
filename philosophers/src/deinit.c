/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:38:00 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 18:38:01 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deinit_philos(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->count)
	{
		pthread_join(*ctx->philos[i]->thread, NULL);
		free(ctx->philos[i]->thread);
		free(ctx->philos[i++]);
	}
	free(ctx->philos);
}

void	deinit_forks(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->count)
	{
		pthread_mutex_destroy(ctx->forks[i]);
		free(ctx->forks[i++]);
	}
	pthread_mutex_destroy(&ctx->printing);
	free(ctx->forks);
}
