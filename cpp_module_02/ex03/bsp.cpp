/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:52:49 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 20:19:24 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

inline bool side(const Point &p, const Point &a, const Point &b) {
  return ((b.getY() - a.getY()) * (p.getX() - a.getX()) +
          ((b.getX() * -1) + a.getX()) * (p.getY() - a.getY())) > 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
  return side(p, a, b) && side(p, b, c) && side(p, c, a);
}
