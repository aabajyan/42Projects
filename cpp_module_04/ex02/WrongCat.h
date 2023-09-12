/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:44:54 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 01:41:52 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_H__
#define __WRONG_CAT_H__
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
  using WrongAnimal::operator=;

  WrongCat();
  WrongCat(const WrongCat &other);
  ~WrongCat();

  void makeSound() const;
};

#endif // __WRONG_CAT_H__
