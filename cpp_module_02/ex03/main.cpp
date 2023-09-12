/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:13:41 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/01 17:29:17 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

  // No triangle
  {
    Point a(0.0f, 0.0f);
    Point b(0.0f, 0.0f);
    Point c(0.0f, 0.0f);
    Point p(0.0f, 0.0f);
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl; // false
  }

  // Test inside
  {
    Point a(Fixed(1), Fixed());
    Point b(Fixed(-1), Fixed());
    Point c(Fixed(), Fixed(1));
    Point p(Fixed(0.4f), Fixed(0.4f));
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl; // true
  }

  // Test edges
  {
    Point a(Fixed(1), Fixed());
    Point b(Fixed(-1), Fixed());
    Point c(Fixed(), Fixed(1));
    Point p(Fixed(0.5f), Fixed(0.5f));
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl; // false
  }

  // Test vertex
  {
    Point a(Fixed(1), Fixed());
    Point b(Fixed(-1), Fixed());
    Point c(Fixed(), Fixed(1));
    Point p(Fixed(), Fixed(0.5f));
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl; // true
    std::cout << (bsp(a, b, c, a) ? "true" : "false") << std::endl; // false
    std::cout << (bsp(a, b, c, b) ? "true" : "false") << std::endl; // false
    std::cout << (bsp(a, b, c, c) ? "true" : "false") << std::endl; // false
  }

  return 0;
}
