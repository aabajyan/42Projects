/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:43:05 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:35:38 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
#define __ITER_H__

template <typename T>
void iter(T arr[], int length, void (*callback)(const T &)) {
  for (int i = 0; i < length; ++i)
    callback(arr[i]);
}

#endif // __ITER_H__
