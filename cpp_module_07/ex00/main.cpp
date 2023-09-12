/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:34:10 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:37:21 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.h"
#include <iostream>

int main() {

  std::cout << "SWAP:\n";

  int a = 42;
  int b = 21;
  std::cout << "A: " << a << " B: " << b << "\n";
  swap(a, b);
  std::cout << "A: " << a << " B: " << b << "\n";

  std::cout << "MAX:\n";
  std::cout << max(4, 42) << "\n";
  std::cout << max(4.0f, 42.0f) << "\n";
  std::cout << max('a', 'A') << "\n";
  std::cout << max("Hello", "World") << "\n";

  std::cout << "MIN:\n";
  std::cout << min(4, 42) << "\n";
  std::cout << min(4.0f, 42.0f) << "\n";
  std::cout << min('a', 'A') << "\n";
  std::cout << min("Hello", "World") << "\n";

  return 0;
}
