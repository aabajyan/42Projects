/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:00:25 by aabajyan          #+#    #+#             */
/*   Updated: 2021/07/29 21:35:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_sort *sort, bool silent)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(sort->first) == 0)
		return ;
	temp = sort->first;
	last = stack_last(sort->first);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	sort->first = last;
	announce("rra\n", silent);
}

void	rrb(t_sort *sort, bool silent)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(sort->second) == 0)
		return ;
	temp = sort->second;
	last = stack_last(sort->second);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = temp;
	temp->prev = last;
	sort->second = last;
	announce("rrb\n", silent);
}

void	rrr(t_sort *sort, bool silent)
{
	rra(sort, true);
	rrb(sort, true);
	announce("rrr\n", silent);
}
