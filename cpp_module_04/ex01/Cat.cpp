/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:29:17 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 18:58:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain("CatIdeas")) {
  std::cout << "Cat::Cat() called\n";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
  std::cout << "Cat::Cat(const Cat &other) called\n";
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat &Cat::operator=(const Cat &other) called\n";
  if (this != &other)
    *brain = *other.brain;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat::~Cat() called\n";
  delete brain;
}

void Cat::makeSound() const { std::cout << "Meow\n"; }

const std::string *Cat::getIdeas() const { return brain->getIdeas(); }

const std::string &Cat::getIdea() const { return brain->getIdea(); }
