/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:07:33 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/12 14:53:26 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*stack_clone(t_stack *stack)
{
	t_stack	*result;

	if (stack == NULL)
		return (NULL);
	result = stack_new(stack->value);
	if (stack->next == NULL)
		return (result);
	while (stack != NULL)
	{
		stack_push(result, stack->value);
		stack = stack->next;
	}
	return (result);
}

static void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static t_stack	*stack_paritition(t_stack *l, t_stack *h)
{
	int		x;
	t_stack	*i;
	t_stack	*j;

	x = h->value;
	i = l->prev;
	j = l;
	while (j != h)
	{
		if (j->value <= x)
		{
			if (i != NULL)
				i = i->next;
			else
				i = l;
			swap(&i->value, &j->value);
		}
		j = j->next;
	}
	if (i != NULL)
		i = i->next;
	else
		i = l;
	swap(&i->value, &h->value);
	return (i);
}

static void	stack_quicksort(t_stack *l, t_stack *h)
{
	t_stack	*p;

	if (h != NULL && l != h && l != h->next)
	{
		p = stack_paritition(l, h);
		stack_quicksort(l, p->prev);
		stack_quicksort(p->next, h);
	}
}

t_stack	*stack_sort(t_stack *stack)
{
	t_stack	*result;

	result = stack_clone(stack);
	stack_quicksort(result, stack_last(result));
	return (result);
}
