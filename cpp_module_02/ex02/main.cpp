/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:13:41 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 17:33:51 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int main(void) {
  Fixed a(12);
  Fixed const b(Fixed(5.00f) * Fixed(2));
  std::cout << "a = " << a << "\n";
  std::cout << "++a = " << ++a << "\n";
  std::cout << "a++ = " << a++ << "\n";
  std::cout << "a = " << a << "\n";
  std::cout << "b = " << b << "\n";
  std::cout << "a < b = " << ((a < b) ? "true" : "false") << "\n";
  std::cout << "a <= b = " << ((a <= b) ? "true" : "false") << "\n";
  std::cout << "a > b = " << ((a > b) ? "true" : "false") << "\n";
  std::cout << "a >= b = " << ((a >= b) ? "true" : "false") << "\n";
  std::cout << "a == b = " << ((a == b) ? "true" : "false") << "\n";
  std::cout << "a != b = " << ((a != b) ? "true" : "false") << "\n";
  std::cout << "a == a = " << ((a == a) ? "true" : "false") << "\n";
  std::cout << "a + b = " << a + b << "\n";
  std::cout << "a - b = " << a - b << "\n";
  std::cout << "a / b = " << a / b << "\n";
  std::cout << "a * b = " << a * b << "\n";
  std::cout << "max(a, b) = " << Fixed::max(a, b) << "\n";
  std::cout << "min(a, b) = " << Fixed::min(a, b) << "\n";
  return 0;
}
