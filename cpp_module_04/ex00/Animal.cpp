/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:31:24 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 01:44:42 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal() : m_type("Unknown") {
  std::cout << "Animal::Animal() called\n";
}

Animal::Animal(const std::string &type) : m_type(type) {
  std::cout << "Animal::Animal(const std::string &type) called\n";
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal &Animal::operator=(const Animal &other) called\n";
  if (this != &other)
    m_type = other.m_type;
  return *this;
}

Animal::~Animal() { std::cout << "Animal::~Animal() called\n"; }

Animal::Animal(const Animal &other) : m_type(other.m_type) {
  std::cout << "Animal::Animal(const Animal &other) called\n";
}

void Animal::makeSound() const { std::cout << "Generic Animal sound\n"; }

const std::string &Animal::getType() const { return m_type; }
