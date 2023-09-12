/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:27:03 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/15 20:21:04 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __I_MATERIA_SOURCE_H__
#define __I_MATERIA_SOURCE_H__
#include "AMateria.h"

class IMateriaSource {
public:
  virtual ~IMateriaSource(){};
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif // __I_MATERIA_SOURCE_H__
