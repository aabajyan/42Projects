/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:26 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 16:45:54 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_sort *sort, bool silent)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(sort->first) < 1)
		return ;
	last = stack_last(sort->first);
	temp = sort->first;
	sort->first = temp->next;
	sort->first->prev = NULL;
	last->next = temp;
	temp->prev = last;
	last = last->next;
	last->next = NULL;
	announce("ra\n", silent);
}

void	rb(t_sort *sort, bool silent)
{
	t_stack	*temp;
	t_stack	*last;

	if (stack_size(sort->second) < 1)
		return ;
	last = stack_last(sort->second);
	temp = sort->second;
	sort->second = temp->next;
	sort->second->prev = NULL;
	last->next = temp;
	temp->prev = last;
	last = last->next;
	last->next = NULL;
	announce("rb\n", silent);
}

void	rr(t_sort *sort, bool silent)
{
	ra(sort, true);
	rb(sort, true);
	announce("rr\n", silent);
}
