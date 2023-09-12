/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:30:51 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/09 17:29:45 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog") { std::cout << "Dog::Dog() called\n"; }

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog::Dog(const Dog &other) called\n";
}

Dog::~Dog() { std::cout << "Dog::~Dog() called\n"; }

void Dog::makeSound() const { std::cout << "Woof\n"; }
