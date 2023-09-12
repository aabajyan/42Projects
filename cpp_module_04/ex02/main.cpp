/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:32 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/18 18:07:59 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"
#include <iostream>

int main() {

  {
    Dog a;
    {
      Dog b(a);
      std::cout << b.getIdea() << "\n";
    }
    std::cout << a.getIdea() << "\n";
  }

  Dog *dog = new Dog();
  Cat *cat = new Cat();

  std::cout << "What's on your mind?\n";
  std::cout << dog->getIdea() << "\n";
  std::cout << cat->getIdea() << "\n";

  Cat *other_cat = new Cat(*cat);
  Dog *other_dog = new Dog;
  *other_dog = *dog;

  std::cout << other_cat->getIdea() << "\n";
  std::cout << other_dog->getIdea() << "\n";

  delete other_dog;
  delete other_cat;
  delete dog;
  delete cat;

  const WrongAnimal *wrong_cat = new WrongCat();
  const WrongCat *not_really_wrong_cat = new WrongCat();

  std::cout << wrong_cat->getType() << "\n";
  std::cout << not_really_wrong_cat->getType() << "\n";
  wrong_cat->makeSound();
  not_really_wrong_cat->makeSound();

  delete wrong_cat;
  delete not_really_wrong_cat;

  Animal *animals[10];

  for (size_t i = 0; i <= 10; ++i) {
    if (i <= 5) {
      animals[i] = new Dog;
      continue;
    }
    animals[i] = new Cat;
  }

  animals[2]->makeSound();
  animals[8]->makeSound();

  for (size_t i = 0; i <= 10; ++i)
    delete animals[i];

  return 0;
}
