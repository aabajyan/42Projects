/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:19:55 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 16:45:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	main(int argc, char **argv)
{
	t_sort	*sort;

	if (argc < 2)
		return (0);
	if (!is_numeric_array(argc, argv))
		on_error();
	sort = sort_create(argc, argv);
	if (sort == NULL)
		on_error();
	if (has_duplicates(sort->first) == true)
	{
		sort_destroy(sort);
		on_error();
	}
	sort_run(sort);
	sort_destroy(sort);
	return (0);
}
