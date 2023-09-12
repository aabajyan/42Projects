/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:40:57 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 17:30:02 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : m_index(0), m_size(0) {}

bool PhoneBook::is_numeric(const std::string &src) {
  for (size_t i = 0; i < src.size(); ++i)
    if (!std::isdigit(src[i]))
      return false;
  return true;
}

void PhoneBook::add() {
  std::string str;

  if (m_index >= PHONEBOOK_MAX_SIZE) {
    m_index = 0;
    std::cout << "Warning: Starting from 0 again. This will overwrite remaining contacts" << std::endl;
  }

  if (!obtain_value(str, "First Name"))
    return;
  m_data[m_index].set_first_name(str);

  if (!obtain_value(str, "Last Name"))
    return;
  m_data[m_index].set_last_name(str);

  if (!obtain_value(str, "Nickname"))
    return;
  m_data[m_index].set_nickname(str);

  if (!obtain_value(str, "Phone Number"))
    return;
  m_data[m_index].set_phone(str);

  if (!obtain_value(str, "Darkest Secret"))
    return;
  m_data[m_index].set_secret(str);

  if (m_size < PHONEBOOK_MAX_SIZE) m_size++;

  std::cout << "Contact " << m_index++ << " has been saved!" << std::endl;
}

void PhoneBook::search() {
  std::string input;
  while (!std::cin.eof()) {
    std::cout << "search > ";
    if (!std::getline(std::cin, input) || input == "EXIT")
      break;
    if (input != "") {
      if (!is_numeric(input)) {
        std::cout << "Error: " << input << " is not numeric." << std::endl;
        continue;
      }
      print(std::atoi(input.c_str()));
    }
  }
}

bool PhoneBook::is_empty(const std::string &src) {
  for (size_t i = 0; i < src.length(); ++i)
    if (!std::isspace(src[i]))
      return false;
  return true;

}

bool PhoneBook::obtain_value(std::string& dest, const std::string &name) {
  std::cout << name << ": ";
  std::getline(std::cin, dest);
  if (is_empty(dest)) {
    std::cout << "Value " << name << " should not be empty." << std::endl;
    return false; 
  }
  return true;
}

void PhoneBook::print(size_t index) {
  if (index >= m_size) {
    std::cout << index << " not found." << std::endl;
    return;
  }

  std::cout << "|" << std::setw(10) << index << "|";
  print_formatted(m_data[index].get_first_name());
  print_formatted(m_data[index].get_last_name());
  print_formatted(m_data[index].get_nickname());
  std::cout << std::endl;
}

void PhoneBook::print_formatted(const std::string &src) {
  if (src.size() > 10) {
    std::cout << src.substr(0, 9) << ".|";
    return;
  }
  std::cout << std::setw(10) << src << "|";
}
