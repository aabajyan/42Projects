/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:29:26 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 19:59:53 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap()
    : m_name("Unknown"), m_hitpoints(10), m_energypoints(10),
      m_attackdamage(0) {
  std::cout << "ClapTrap default has been created\n";
}

ClapTrap::ClapTrap(const std::string &name)
    : m_name(name), m_hitpoints(10), m_energypoints(10), m_attackdamage(0) {
  std::cout << "ClapTrap " << m_name << " has been created.\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : m_name(other.m_name), m_hitpoints(other.m_hitpoints), m_energypoints(other.m_energypoints), 
    m_attackdamage(other.m_attackdamage) {
  std::cout << "ClapTrap " << other.m_name << " has been copied.\n";
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << m_name << " has been destroyed\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap" << m_name << " operator assignment called from " << other.m_name << ".\n";
  if (this != &other) {
    m_name = other.m_name;
    m_attackdamage = other.m_attackdamage;
    m_energypoints = other.m_energypoints;
    m_hitpoints = other.m_hitpoints;
  }
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  if (m_hitpoints == 0) {
    std::cout << "Can't attack " << target << ", because " << m_name
              << " is dead.\n";
    return;
  }
  if (m_energypoints == 0) {
    std::cout << "Can't attack " << target << ", because " << m_name
              << " has no energy.\n";
    return;
  }
  m_energypoints--;
  std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing "
            << m_attackdamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (m_hitpoints == 0) {
    std::cout << "Can't damage " << m_name << ", because they are dead.\n";
    return;
  }
  unsigned int actual_amount = amount;
  if (actual_amount > m_hitpoints)
    actual_amount = m_hitpoints;
  m_hitpoints -= actual_amount;
  std::cout << "ClapTrap " << m_name << " took " << amount
            << " amount of damage. Hitpoint is now " << m_hitpoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (m_hitpoints == 0) {
    std::cout << "Can't heal " << m_name << ", because they are dead.\n";
    return;
  }
  if (m_energypoints == 0) {
    std::cout << "Can't heal " << m_name << ", because they have no energy.\n";
    return;
  }
  m_energypoints--;
  m_hitpoints += amount;
  std::cout << m_name << " has been healed " << amount << ". hitpoint is now "
            << m_hitpoints << "\n";
}

void ClapTrap::setAttackDamange(unsigned int damage) {
  m_attackdamage = damage;
}
