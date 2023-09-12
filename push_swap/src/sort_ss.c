/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:57:56 by aabajyan          #+#    #+#             */
/*   Updated: 2021/07/29 21:35:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_sort *sort, bool silent)
{
	int	temp;

	temp = sort->first->value;
	sort->first->value = sort->first->next->value;
	sort->first->next->value = temp;
	announce("sa\n", silent);
}

void	sb(t_sort *sort, bool silent)
{
	int	temp;

	temp = sort->second->value;
	sort->second->value = sort->second->next->value;
	sort->second->next->value = temp;
	announce("sb\n", silent);
}

void	ss(t_sort *sort, bool silent)
{
	sa(sort, true);
	sb(sort, true);
	announce("ss\n", silent);
}
