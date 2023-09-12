/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 23:26:45 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 18:19:14 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_count(t_ctx *ctx, bool *end)
{
	int	i;

	if (*end == true)
		return ;
	i = 0;
	while (i < ctx->count && ctx->eating_count != -1
		&& ctx->philos[i]->ate_count >= ctx->eating_count)
		i++;
	if (i >= ctx->count)
	{
		ctx->end_sim = true;
		*end = true;
	}
}

static bool	someones_dead(t_ctx *ctx)
{
	int				i;
	bool			end;

	i = 0;
	end = false;
	while (i < ctx->count && ctx->end_sim == false)
	{
		pthread_mutex_lock(&ctx->check);
		if (timestamp() - ctx->philos[i]->ate_at > (uint64_t)ctx->time_to_die)
		{
			print(ctx->philos[i], DEAD);
			ctx->end_sim = true;
			end = true;
		}
		pthread_mutex_unlock(&ctx->check);
		usleep(100);
		++i;
	}
	check_count(ctx, &end);
	return (end);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc != 5 && argc != 6)
		return (error("Argument"));
	ctx = (t_ctx){.end_sim = false, .eating_count = -1, .start = timestamp()};
	if (!(load_arg(&ctx.count, argv[1])
			&& load_arg(&ctx.time_to_die, argv[2])
			&& load_arg(&ctx.time_to_eat, argv[3])
			&& load_arg(&ctx.time_to_sleep, argv[4])
			&& (argc == 5 || load_arg(&ctx.eating_count, argv[5]))))
		return (error("Argument"));
	init_forks(&ctx);
	init_philos(&ctx);
	while (!someones_dead(&ctx))
		continue ;
	deinit_philos(&ctx);
	deinit_forks(&ctx);
	return (0);
}
