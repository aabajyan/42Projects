/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:30:24 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 00:07:32 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__
#include "Animal.h"

class Dog : public Animal {
public:
  using Animal::operator=;

  Dog();
  Dog(const Dog &other);
  virtual ~Dog();

  void makeSound() const;
};

#endif // __DOG_H__
