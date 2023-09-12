/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:06:12 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/22 21:16:35 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_H__
#define __EASYFIND_H__
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int position) {
  return std::find(container.begin(), container.end(), position);
}

#endif // __EASYFIND_H__
