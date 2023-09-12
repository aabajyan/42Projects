/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:06:01 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 17:24:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static unsigned char	g_buffer;

void	handle(int sig)
{
	static int	bit;

	if (sig == SIGUSR1)
		g_buffer |= 1 << bit++;
	else if (sig == SIGUSR2)
		g_buffer |= 0 << bit++;
	if (bit > 7)
	{
		if (g_buffer == '\0')
			ft_putchar_fd('\n', STDOUT_FILENO);
		ft_putchar_fd(g_buffer, STDOUT_FILENO);
		bit = 0;
		g_buffer = 0;
	}
}

int	main(void)
{
	g_buffer = 0;
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	ft_putstr_fd("PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	while (true)
		pause();
	return (0);
}
