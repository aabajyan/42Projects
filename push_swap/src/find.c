/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:55:03 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 15:01:07 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*find_smallest(t_stack	*stack)
{
	t_stack	*small;

	small = stack;
	while (stack != NULL)
	{
		if (small->value > stack->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

t_stack	*find_highest(t_stack	*stack)
{
	t_stack	*small;

	small = stack;
	while (stack != NULL)
	{
		if (small->value < stack->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
}

void	push_stack_to_b(t_sort *sort, t_stack *stack)
{
	int	value;

	value = stack->value;
	if (sort_ra_or_rra(sort->first, stack_index(stack)))
		while (sort->first->value != value)
			ra(sort, false);
	else
		while (sort->first->value != value)
			rra(sort, false);
	pb(sort, false);
}

void	push_stack_to_a(t_sort *sort, t_stack *stack)
{
	int	value;

	value = stack->value;
	if (sort_ra_or_rra(sort->second, stack_index(stack)))
		while (sort->second->value != value)
			rb(sort, false);
	else
		while (sort->second->value != value)
			rrb(sort, false);
	pa(sort, false);
}
