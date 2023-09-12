/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:13:52 by aabajyan          #+#    #+#             */
/*   Updated: 2021/07/13 12:14:01 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*stack_load_from_args(int argc, char **argv)
{
	t_stack	*result;
	int		i;

	if (argc <= 1)
		return (NULL);
	result = stack_new(ft_atoi(argv[1]));
	i = 2;
	while (i < argc)
		stack_push(result, ft_atoi(argv[i++]));
	return (result);
}

bool	is_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
