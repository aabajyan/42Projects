/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Charecter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:31:48 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 19:26:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include "Character.h"
#include <iostream>

Character::Character() : m_name(""), m_size(0) {}

Character::Character(const std::string &name) : m_name(name), m_size(0) {}

Character::Character(const Character &other)
    : m_name(other.m_name), m_size(other.m_size) {
  for (int i = 0; i < other.m_size; ++i)
    m_inventory[i] = other.m_inventory[i]->clone();
}

Character::~Character() {
  for (int i = 0; i < m_size; ++i)
    delete m_inventory[i];
}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;
  for (int i = 0; i < m_size; i++)
    delete m_inventory[i];
  m_size = other.m_size;
  m_name = other.m_name;
  for (int i = 0; i < m_size; i++)
    m_inventory[i] = other.m_inventory[i]->clone();
  return *this;
}

const std::string &Character::getName() const { return m_name; }

void Character::equip(AMateria *m) {
  if (!m) {
    std::cout << "AMateria should not be null.\n";
    return;
  }
  if (m_size < CHARACTER_INVENTORY_SIZE) {
    for (int i = 0; i < m_size; ++i)
      if (m == m_inventory[i]) {
        std::cout << "Duplicate pointers are not allowed\n";
        return;
      }
    std::cout << m_name << " has been equipped with " << m->getType()
              << " with index: " << m_size << "\n";
    m_inventory[m_size++] = m;

    return;
  }

  std::cout << "Unable to equip " << m->getType() << ", inventory full.\n";
}

void Character::unequip(int idx) {
  int i = idx;
  if (idx >= 0 && idx < m_size) {
    while (++idx < m_size)
      m_inventory[idx - 1] = m_inventory[idx];
    m_size--;
    return;
  }
  std::cout << "Invalid index " << i << ".\n";
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < m_size && m_inventory[idx]) {
    m_inventory[idx]->use(target);
    return;
  }
  std::cout << "Can't use materia, index " << idx << " is empty\n";
}
