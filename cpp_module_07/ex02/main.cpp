/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 01:50:15 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/21 18:16:04 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"
#include <cstdlib>
#include <iostream>
#include <string>

#define MAX_VAL 750

int main() {
  {
    Array<bool> empty;
    try {
      empty[0] = false;
    } catch (const std::exception &e) {
      std::cout << e.what() << "\n";
    }
  }

  {
    Array<int> x(4);
    x[0] = 2;
    x[1] = 4;
    x[2] = 6;
    x[3] = 8;

    for (size_t i = 0; i < x.size(); ++i)
      std::cout << "x[" << i << "] = " << x[i] << "\n";

    try {
      x[4000] = 42;
    } catch (const std::exception &e) {
      std::cout << e.what() << "\n";
    }
  }

  {
    Array<std::string> x(2);
    x[0] = "Hello";
    x[1] = "World";

    for (size_t i = 0; i < x.size(); ++i)
      std::cout << "x[" << i << "] = " << x[i] << "\n";

    try {
      x[2] = 42;
    } catch (const std::exception &e) {
      std::cout << e.what() << "\n";
    }
  }

  {
    Array<std::string> a(3);
    a[0] = "Hello";
    a[1] = "From";
    a[2] = "42";

    Array<std::string> b = a;
    b[0] = "Heloooo";


    for (size_t i = 0; i < a.size(); ++i)
      std::cout << a[i] << " " << b[i] << "\n";
  }

  {
    Array<int> a(2);
    a[0] = 1;
    a[1] = 2;

    Array<int> b;

    std::cout << "a.size() = " << a.size() << "\n";

    a = b;

    std::cout << "a.size() = " << a.size() << "\n";

    Array<int> c(b);

    std::cout << "c.size() = " << c.size() << "\n";

  }

  std::cout << "From Subject.pdf\n";

  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  std::srand(std::time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = std::rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }

  delete[] mirror;

  return 0;
}
