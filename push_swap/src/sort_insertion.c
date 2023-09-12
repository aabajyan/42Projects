/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:35:37 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 12:14:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static bool	sort_find_lower_than(t_stack **m, t_stack *t, int value)
{
	while (t != NULL)
	{
		if (t->value <= value)
		{
			*m = t;
			return (true);
		}
		t = t->next;
	}
	*m = NULL;
	return (false);
}

static void	push_to_a(t_sort *sort)
{
	t_stack	*find;

	while (stack_size(sort->second) > 0)
	{
		find = find_highest(sort->second);
		push_stack_to_a(sort, find);
	}
}

void	sort_insertion(t_sort *sort, int stack)
{
	int		median;
	t_stack	*find;
	int		i;
	int		j;
	int		split;

	sort->sorted = stack_sort(sort->first);
	split = stack_size(sort->first) / stack;
	i = 0;
	j = 0;
	while (j++ < stack - 1)
	{
		i += split;
		median = stack_get(sort->sorted, i)->value;
		while (sort_find_lower_than(&find, sort->first, median))
			push_stack_to_b(sort, find);
	}
	while (stack_size(sort->first) > 1)
	{
		find = find_smallest(sort->first);
		push_stack_to_b(sort, find);
	}
	push_to_a(sort);
}
