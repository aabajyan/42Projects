/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:11:34 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/18 18:25:18 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIAL_SOURCE_H__
#define __MATERIAL_SOURCE_H__
#include "IMateriaSource.h"

#define MATERIAL_SIZE 4

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &other);

  void learnMateria(AMateria *materia);
  AMateria *createMateria(const std::string &type);

private:
  AMateria *m_materias[MATERIAL_SIZE];
  int m_n_learned;
};

#endif // __MATERIAL_SOURCE_H__
