/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:12 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 20:19:17 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
#define __POINT_H__
#include "Fixed.h"

class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(const Fixed &x, const Fixed &y);
  Point(const Point &other);
  Point &operator=(const Point &other);
  bool operator==(const Point &other) const;
  ~Point();

  const Fixed &getX() const;
  const Fixed &getY() const;

private:
  const Fixed m_x;
  const Fixed m_y;
};

#endif // __POINT_H__
