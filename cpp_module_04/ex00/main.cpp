/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:32 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/13 10:08:26 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << "\n";
  std::cout << i->getType() << "\n";
  i->makeSound();
  j->makeSound();
  meta->makeSound();

  delete meta;
  delete i;
  delete j;

  const WrongAnimal *wrong_animal = new WrongAnimal();
  const WrongAnimal *wrong_cat = new WrongCat();
  const WrongCat *not_really_wrong_cat = new WrongCat();

  std::cout << wrong_animal->getType() << "\n";
  std::cout << wrong_cat->getType() << "\n";
  std::cout << not_really_wrong_cat->getType() << "\n";
  wrong_animal->makeSound();
  wrong_cat->makeSound();
  not_really_wrong_cat->makeSound();

  delete wrong_animal;
  delete wrong_cat;
  delete not_really_wrong_cat;

  return 0;
}
