/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:26:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 00:07:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__
#include "Animal.h"

class Cat : public Animal {
public:
  using Animal::operator=;

  Cat();
  Cat(const Cat &other);
  virtual ~Cat();

  void makeSound() const;
};

#endif // __CAT_H__
