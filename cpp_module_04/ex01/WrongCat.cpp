/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:45:30 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/13 09:54:59 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const { std::cout << "Meow\n"; }
