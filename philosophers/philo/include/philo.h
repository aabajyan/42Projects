/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:33:42 by aabajyan          #+#    #+#             */
/*   Updated: 2021/10/18 18:37:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK "has taken a fork"
# define THINKING "is thinking"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define DEAD "died"

struct	s_philo;
typedef struct s_ctx
{
	bool			end_sim;
	int64_t			count;
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_to_sleep;
	int64_t			eating_count;
	pthread_t		*threads;
	struct s_philo	**philos;
	pthread_mutex_t	**forks;
	pthread_mutex_t	check;
	pthread_mutex_t	printing;
	uint64_t		start;
}	t_ctx;

typedef struct s_philo
{
	t_ctx			*ctx;
	pthread_t		*thread;
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int64_t			ate_at;
	int64_t			ate_count;
}	t_philo;

void		init_philos(t_ctx *ctx);
void		init_forks(t_ctx *ctx);
void		*thread_philo(void *arg);
void		deinit_philos(t_ctx *ctx);
void		deinit_forks(t_ctx *ctx);
void		print(t_philo *philo, const char *action);
uint64_t	timestamp(void);
bool		load_arg(int64_t *ctx, char *arg);
int64_t		ft_atoll(const char *str);
int			error(const char *msg);

#endif
