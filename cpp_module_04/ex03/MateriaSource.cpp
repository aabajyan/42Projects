/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:28:02 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 19:14:47 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include <iostream>

MateriaSource::MateriaSource() : m_n_learned(0) {}

MateriaSource::MateriaSource(const MateriaSource &other)
    : m_n_learned(other.m_n_learned) {
  for (int i = 0; i < MATERIAL_SIZE; ++i) {
    if (other.m_materias[i] != NULL) {
      m_materias[i] = other.m_materias[i]->clone();
      continue;
    }
    m_materias[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < m_n_learned; ++i)
    if (m_materias[i] != NULL)
      delete m_materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this != &other) {
    m_n_learned = other.m_n_learned;
    for (int i = 0; i < MATERIAL_SIZE; ++i) {
      delete m_materias[i];
      if (other.m_materias[i] != NULL) {
        m_materias[i] = other.m_materias[i]->clone();
        continue;
      }
      m_materias[i] = NULL;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
  if (materia && m_n_learned < MATERIAL_SIZE) {
    std::cout << "Learned materia " << materia->getType()
              << " and pushed to index " << m_n_learned << ".\n";
    m_materias[m_n_learned] = materia;
    m_n_learned++;
    return;
  }
  std::cout << "Unable to learn " << materia->getType()
            << ", out of capacity.\n";
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < m_n_learned; ++i)
    if (m_materias[i] && m_materias[i]->getType() == type) {
      std::cout << "Created Materia " << m_materias[i]->getType() << "\n";
      return m_materias[i]->clone();
    }
  std::cout << "Unknown metaria '" << type << "'.\n";
  return NULL;
}
