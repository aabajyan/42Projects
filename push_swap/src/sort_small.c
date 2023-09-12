/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:44:42 by aabajyan          #+#    #+#             */
/*   Updated: 2021/07/14 12:50:46 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sort_3(t_sort *sort)
{
	int	first;
	int	second;
	int	third;

	first = stack_get(sort->first, 0)->value;
	second = stack_get(sort->first, 1)->value;
	third = stack_get(sort->first, 2)->value;
	if (first > second && second > third && first > third)
	{
		ra(sort, false);
		sa(sort, false);
	}
	else if (first < second && second > third && first < third)
	{
		sa(sort, false);
		ra(sort, false);
	}
	else if (first > second && second < third && first < third)
		sa(sort, false);
	else if (first > second && second < third && first > third)
		ra(sort, false);
	else if (first < second && second > third && first > third)
		rra(sort, false);
}

void	sort_4(t_sort *sort)
{
	sort_move_small_values(sort, 2);
	if (sort->first->value > sort->first->next->value)
		sa(sort, false);
	if (sort->second->value < sort->second->next->value)
		sb(sort, false);
	while (stack_size(sort->second) > 0)
		pa(sort, false);
}

void	sort_5(t_sort *sort)
{
	sort_move_small_values(sort, 3);
	sort_3(sort);
	while (stack_size(sort->second) > 0)
		pa(sort, false);
}
