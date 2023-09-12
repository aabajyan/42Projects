/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:29 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 20:19:14 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point() : m_x(0), m_y(0) {}

Point::Point(const float x, const float y) : m_x(x), m_y(y) {}

Point::Point(const Fixed &x, const Fixed &y) : m_x(x), m_y(y) {}

Point::Point(const Point &other) : m_x(other.m_x), m_y(other.m_y) {}

Point::~Point() {}

const Fixed &Point::getX() const { return m_x; }
const Fixed &Point::getY() const { return m_y; }

Point &Point::operator=(const Point &other) {
  if (this != &other) {
    (Fixed) m_x = other.getX();
    (Fixed) m_y = other.getY();
  }
  return *this;
}

bool Point::operator==(const Point &other) const {
  return (other.m_x == m_x && other.m_y == m_y);
}
