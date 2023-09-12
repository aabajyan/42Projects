/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:42:43 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:35:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.h"
#include <iostream>

template <typename T> void print(const T &number) {
  std::cout << "value is " << number << "\n";
}

int main() {
  int numbers[] = {532, 643, 4, 5, 43, 2, 53, 643};
  char chars[] = {'A', 'B', 'G', 'F', 'Q', 'Z', 'X', 'D'};

  iter(numbers, 8, print);
  iter(chars, 8, print);

  return 0;
}
