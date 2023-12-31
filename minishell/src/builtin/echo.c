/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:56:56 by araramya          #+#    #+#             */
/*   Updated: 2022/03/08 15:26:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	echo_check_flag(bool *endline, char *arg)
{
	size_t	i;

	i = 0;
	if (arg && arg[i] == '-')
	{
		while (arg[++i] != '\0')
			if (arg[i] != 'n')
				return (false);
		if (*endline == true)
			*endline = false;
		return (true);
	}
	return (false);
}

int	builtin_echo(int argc, char **argv)
{
	bool	endline;
	bool	check_needed;
	int		i;

	i = 1;
	endline = true;
	check_needed = true;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!check_needed || !echo_check_flag(&endline, argv[i]))
			{
				if (check_needed)
					check_needed = false;
				printf("%s", argv[i]);
				if (i + 1 < argc)
					printf(" ");
			}
			i++;
		}
	}
	if (endline)
		printf("\n");
	return (0);
}
