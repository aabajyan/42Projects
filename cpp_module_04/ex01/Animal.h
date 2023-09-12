/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:25:45 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 01:45:14 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <string>

class Animal {
public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &other);
  virtual ~Animal();

  Animal &operator=(const Animal &other);

  const std::string &getType() const;
  virtual void makeSound() const;

protected:
  std::string m_type;
};

#endif // __ANIMAL_H__
