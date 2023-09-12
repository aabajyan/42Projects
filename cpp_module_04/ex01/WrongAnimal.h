/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:36:56 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 02:05:28 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL_H__
#define __WRONG_ANIMAL_H__
#include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &other);
  virtual ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &other);

  const std::string &getType() const;
  void makeSound() const;

protected:
  std::string m_type;
};

#endif // __WRONG_ANIMAL_H__
