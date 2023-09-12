/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:26:43 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/25 19:03:56 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*ft_readfile(const char *file);
char	*ft_strappend(char *s1, char const *s2);
bool	ft_isspace(char c);
bool	ft_endswith(const char *str, const char *suffix);

#endif
