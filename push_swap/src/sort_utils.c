/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:46:01 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 14:51:26 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*stack_find(t_stack *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

bool	sort_ra_or_rra(t_stack *stack, int position)
{
	int	size;
	int	middle;

	size = stack_size(stack);
	middle = size / 2;
	if (size % 2 != 0)
		middle++;
	return (position < middle);
}

void	sort_move_small_values(t_sort *sort, int wsize)
{
	t_stack	*small;
	t_stack	*tmp;
	int		size;
	int		i;

	while (stack_size(sort->first) > wsize)
	{
		i = 0;
		size = stack_size(sort->first);
		small = sort->first;
		while (i < size)
		{
			tmp = stack_get(sort->first, i);
			if (tmp && tmp->value < small->value)
				small = tmp;
			++i;
		}
		if (sort_ra_or_rra(sort->first, stack_index(small)))
			while (sort->first->value != small->value)
				ra(sort, false);
		else
			while (sort->first->value != small->value)
				rra(sort, false);
		pb(sort, false);
	}
}
