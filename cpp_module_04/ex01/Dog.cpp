/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:30:51 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 18:58:12 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain("DogIdeas")) {
  std::cout << "Dog::Dog() called\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Dog::Dog(const Dog &other) called\n";
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog &Dog::operator=(const Dog &other) called\n";
  if (this != &other)
    *brain = *other.brain;
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog::~Dog() called\n";
  delete brain;
}

void Dog::makeSound() const { std::cout << "Woof\n"; }

const std::string *Dog::getIdeas() const { return brain->getIdeas(); }

const std::string &Dog::getIdea() const { return brain->getIdea(); }
