/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:29:17 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/09 16:30:25 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat") { std::cout << "Cat::Cat() called\n"; }

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat::Cat(const Cat &other) called\n";
}

Cat::~Cat() { std::cout << "Cat::~Cat() called\n"; }

void Cat::makeSound() const { std::cout << "Meow\n"; }
