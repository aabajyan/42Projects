/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:31:48 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:35:34 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
#define __WHATEVER_H__

template <typename T> void swap(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}

template <typename T> T min(const T a, const T b) { return a > b ? b : a; }

template <typename T> T max(const T a, const T b) { return a > b ? a : b; }

#endif // __WHATEVER_H__
