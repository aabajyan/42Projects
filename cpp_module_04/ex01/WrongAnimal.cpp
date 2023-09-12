/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:44:12 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 02:07:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : m_type("Unknown") {
  std::cout << "WrongAnimal::WrongAnimal() called\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : m_type(type) {
  std::cout << "WrongAnimal::WrongAnimal(const std::string &type) called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) "
               "called\n";
  if (this != &other)
    m_type = other.m_type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal::~WrongAnimal() called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : m_type(other.m_type) {
  std::cout << "WrongAnimal::WrongAnimal(const WrongAnimal &other) called\n";
}

void WrongAnimal::makeSound() const {
  std::cout << "Generic WrongAnimal sound\n";
}

const std::string &WrongAnimal::getType() const { return m_type; }
