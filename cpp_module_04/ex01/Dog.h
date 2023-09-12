/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:30:24 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/13 10:21:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
#define __DOG_H__
#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &other);
  ~Dog();

  Dog &operator=(const Dog &other);

  void makeSound() const;
  const std::string *getIdeas() const;
  const std::string &getIdea() const;

private:
  Brain *brain;
};

#endif // __DOG_H__
