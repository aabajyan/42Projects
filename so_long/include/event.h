/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 23:25:07 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/30 16:16:30 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

void	on_init(t_mlx_data	*g, int argc, char **argv);
void	on_error(char *msg);
int		on_loop(t_mlx_data *g);
int		on_close(t_mlx_data *g);
int		on_release(int keycode, t_mlx_data *g);

#endif
