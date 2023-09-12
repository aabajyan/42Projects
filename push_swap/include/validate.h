/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:41:43 by aabajyan          #+#    #+#             */
/*   Updated: 2021/08/15 02:11:03 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

long long	ft_atoll(const char *str);
bool		sort_check_limit(const char *str);
bool		is_numeric_array(int count, char **values);
bool		has_duplicates(t_stack *stack);
void		on_error(void);

#endif /* VALIDATE_H */
