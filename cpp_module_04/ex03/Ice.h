/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:25:18 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/13 09:55:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_H__
#define __ICE_H__
#include "AMateria.h"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  ~Ice();

  Ice &operator=(const Ice &other);

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // __ICE_H__
