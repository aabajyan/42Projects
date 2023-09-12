/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:12:21 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 02:01:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*stack_new(int value)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->sorted = false;
	stack->index = -1;
	stack->value = value;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*stack_push(t_stack *stack, int value)
{
	t_stack	*next;

	if (stack == NULL)
		return (stack_new(value));
	next = stack_new(value);
	stack = stack_last(stack);
	stack->next = next;
	if (next)
		next->prev = stack;
	return (stack_first(stack));
}

t_stack	*stack_before(t_stack *stack, int value)
{
	t_stack	*prev;

	prev = stack_new(value);
	stack = stack_first(stack);
	stack->prev = prev;
	prev->next = stack;
	return (prev);
}

void	stack_pop(t_stack **stack, int pos)
{
	t_stack	*del;

	if (pos < 0 || stack == NULL)
		return ;
	del = stack_get(*stack, pos);
	if (del == NULL)
		return ;
	if (*stack == del)
		*stack = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
}

void	stack_delete(t_stack *stack)
{
	t_stack	*next;

	if (stack == NULL)
		return ;
	next = stack->next;
	if (next != NULL)
		stack_delete(next);
	free(stack);
}
