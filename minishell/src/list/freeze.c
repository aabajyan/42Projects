/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeze.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <aabajyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 23:44:12 by aabajyan          #+#    #+#             */
/*   Updated: 2022/03/08 23:47:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	list_size(t_list *self)
{
	size_t	size;

	if (!self)
		return (0);
	size = 1;
	while (self->next)
	{
		size++;
		self = self->next;
	}
	return (size);
}

char	**list_freeze(t_list *self)
{
	char	**result;
	t_list	*temp;
	size_t	i;

	temp = self;
	i = 0;
	result = ft_calloc(list_size(self) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (temp)
	{
		result[i++] = ft_strdup(temp->value);
		temp = temp->next;
	}
	result[i++] = NULL;
	list_destroy(self);
	return (result);
}
