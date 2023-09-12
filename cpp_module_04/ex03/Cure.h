/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:26:07 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/13 09:55:52 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_H__
#define __CURE_H__
#include "AMateria.h"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  ~Cure();

  Cure &operator=(const Cure &other);

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // __CURE_H__
