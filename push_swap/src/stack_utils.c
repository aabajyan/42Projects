/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:12:20 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 14:51:15 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*stack_last(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_first(t_stack *stack)
{
	while (stack->prev != NULL)
		stack = stack->prev;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	size = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*stack_get(t_stack *stack, int index)
{
	while (index-- > 0)
	{
		if (stack == NULL || stack->next == NULL)
			return (NULL);
		stack = stack->next;
	}
	return (stack);
}

int	stack_index(t_stack *stack)
{
	int	index;

	index = -1;
	while (stack != NULL)
	{
		index++;
		stack = stack->prev;
	}
	return (index);
}
