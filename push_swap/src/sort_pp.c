/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:00:44 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 16:45:58 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_sort *sort, bool silent)
{
	if (stack_size(sort->second) == 0)
		return ;
	if (stack_size(sort->first) > 0)
		sort->first = stack_before(sort->first, sort->second->value);
	else
		sort->first = stack_new(sort->second->value);
	stack_pop(&sort->second, 0);
	announce("pa\n", silent);
}

void	pb(t_sort *sort, bool silent)
{
	if (stack_size(sort->first) == 0)
		return ;
	if (stack_size(sort->second) > 0)
		sort->second = stack_before(sort->second, sort->first->value);
	else
		sort->second = stack_new(sort->first->value);
	stack_pop(&sort->first, 0);
	announce("pb\n", silent);
}
