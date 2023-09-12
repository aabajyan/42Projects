/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:48:15 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 01:57:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include <stdbool.h>
# include "stack.h"

typedef struct s_sort
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*sorted;
}				t_sort;

t_stack	*find_smallest(t_stack	*stack);
t_stack	*find_highest(t_stack	*stack);
void	push_stack_to_a(t_sort *sort, t_stack *stack);
void	push_stack_to_b(t_sort *sort, t_stack *stack);
bool	is_sorted(t_stack *sort);
t_sort	*sort_create(int argc, char **argv);
t_sort	*sort_destroy(t_sort *sort);
void	sort_run(t_sort *sort);
void	sort_3(t_sort *sort);
void	sort_4(t_sort *sort);
void	sort_5(t_sort *sort);
void	sort_insertion(t_sort *sort, int stack);
bool	sort_ra_or_rra(t_stack *stack, int position);
void	sort_move_small_values(t_sort *sort, int wsize);
void	sa(t_sort *sort, bool silent);
void	sb(t_sort *sort, bool silent);
void	ss(t_sort *sort, bool silent);
void	ra(t_sort *sort, bool silent);
void	rb(t_sort *sort, bool silent);
void	rr(t_sort *sort, bool silent);
void	rra(t_sort *sort, bool silent);
void	rrb(t_sort *sort, bool silent);
void	rrr(t_sort *sort, bool silent);
void	pa(t_sort *sort, bool silent);
void	pb(t_sort *sort, bool silent);
void	announce(const char *str, bool silent);

#endif /* SORT_H */
