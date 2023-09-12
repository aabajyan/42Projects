/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:26:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 01:42:29 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
#define __CAT_H__
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &other);
  ~Cat();

  Cat &operator=(const Cat &other);

  void makeSound() const;
  const std::string *getIdeas() const;
  const std::string &getIdea() const;

private:
  Brain *brain;
};

#endif // __CAT_H__
