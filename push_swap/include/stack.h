/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:06:50 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 01:55:43 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	bool			sorted;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_first(t_stack *stack);
t_stack	*stack_new(int value);
t_stack	*stack_load_from_args(int argc, char **argv);
t_stack	*stack_push(t_stack *stack, int value);
t_stack	*stack_before(t_stack *stack, int value);
int		stack_size(t_stack *stack);
int		stack_index(t_stack *stack);
t_stack	*stack_get(t_stack *stack, int index);
t_stack	*stack_clone(t_stack *stack);
t_stack	*stack_sort(t_stack *stack);
void	stack_pop(t_stack **stack, int pos);
t_stack	*stack_find(t_stack *stack, int value);
void	stack_delete(t_stack *stack);

#endif
