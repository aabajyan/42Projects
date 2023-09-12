/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:49 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 16:46:09 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_sort	*sort_create(int argc, char **argv)
{
	int		i;
	t_sort	*result;

	if (argc <= 1)
		return (NULL);
	result = malloc(sizeof(t_sort));
	if (result == NULL)
		return (NULL);
	result->first = NULL;
	result->second = NULL;
	result->sorted = NULL;
	i = 1;
	while (i < argc)
	{
		if (sort_check_limit(argv[i]))
			return (sort_destroy(result));
		result->first = stack_push(result->first, ft_atoi(argv[i++]));
	}
	return (result);
}

void	sort_run(t_sort *sort)
{
	int		size;

	if (is_sorted(sort->first))
		return ;
	size = stack_size(sort->first);
	if (size == 2 && sort->first->value > sort->first->next->value)
		sa(sort, false);
	else if (size == 3)
		sort_3(sort);
	else if (size == 4)
		sort_4(sort);
	else if (size == 5)
		sort_5(sort);
	else if (size <= 300)
		sort_insertion(sort, 4);
	else
		sort_insertion(sort, 8);
}

t_sort	*sort_destroy(t_sort *sort)
{
	if (sort && sort->first)
		stack_delete(sort->first);
	if (sort && sort->second)
		stack_delete(sort->second);
	if (sort && sort->sorted)
		stack_delete(sort->sorted);
	if (sort)
		free(sort);
	return (NULL);
}

void	announce(const char *str, bool silent)
{
	if (silent == false)
		ft_putstr_fd((char *)str, 1);
}
