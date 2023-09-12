/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 01:11:46 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 01:57:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_H
# define NUMBER_H

void	number_init(t_mlx_data *g);
void	number_draw(int number, t_vector pos);
void	number_deinit(void);

#endif /* NUMBER_H */
