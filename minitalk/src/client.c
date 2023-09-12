/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 01:25:41 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 17:23:25 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	length;

	if (argc != 3)
	{
		ft_putstr_fd("usage: ./client [pid] [message]\n", STDOUT_FILENO);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	length = ft_strlen(argv[2]);
	while (i < length + 1)
		send_bit(pid, argv[2][i++]);
	ft_putstr_fd("The message has been received.\n", STDOUT_FILENO);
	return (0);
}
