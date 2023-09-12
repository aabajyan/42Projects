/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 00:05:26 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:30:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.h"
#include "B.h"
#include "Base.h"
#include "C.h"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
  switch (std::rand() % 3) {
  case 0:
    return new A;
  case 1:
    return new B;
  default:
    return new C;
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "A\n";
    return;
  }
  if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "B\n";
    return;
  }
  if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "C\n";
    return;
  }
  std::cout << "Couldn't identify the class\n";
}

void identify(Base &p) {
  try {
    p = dynamic_cast<A &>(p);
    std::cout << "A\n";
    return;
  } catch (...) {
  };

  try {
    p = dynamic_cast<B &>(p);
    std::cout << "B\n";
    return;
  } catch (...) {
  };

  try {
    p = dynamic_cast<C &>(p);
    std::cout << "C\n";
    return;
  } catch (...) {
  };

  std::cout << "Couldn't identify the class\n";
}

int main() {

  std::srand(std::time(NULL));

  Base *base = generate();

  identify(base);
  identify(*base);
  identify(NULL);

  delete base;

  return 0;
}
