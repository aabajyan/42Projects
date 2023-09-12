/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:07:49 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 17:37:31 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main() {

  try {
    Bureaucrat james("James", 2);
    std::cout << james << "\n";

    james.increment();
    std::cout << james << "\n";

    james.increment(2);
    std::cout << james << "\n";

    james.decrement(4);
    std::cout << james << "\n";

    james.increment(1000);

  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    Bureaucrat bob("Bob", 1);
    std::cout << bob << "\n";
    bob.decrement();
  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  try {
    Bureaucrat jaiden("Jaiden", -42);
    std::cout << jaiden << "\n";
  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
  }

  return 0;
}
