/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:42:24 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:27:34 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

int main() {
  PhoneBook phonebook;
  std::string input;
  while (!std::cin.eof()) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "EXIT")
      break;
    if (input == "SEARCH") {
      phonebook.search();
      continue;
    }
    if (input == "ADD") {
      phonebook.add();
      continue;
    }
    std::cout << "Unknown command " << input << std::endl;
  }
  return 0;
}
