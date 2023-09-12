/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:50:58 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 20:38:19 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap default has been created\n";
}

ScavTrap::ScavTrap(const std::string &name) {
  m_name = name;
  m_hitpoints = 100;
  m_energypoints = 50;
  m_attackdamage = 20;
  std::cout << "ScavTrap " << m_name << " has been created\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap " << m_name << " ScavTrap has been copied\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << m_name << " ScavTrap has been destroyed\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap " << m_name << " ScavTrap assignment from " << other.m_name
            << "called\n";
  if (this != &other) {
    m_name = other.m_name;
    m_hitpoints = other.m_hitpoints;
    m_energypoints = other.m_energypoints;
    m_attackdamage = other.m_attackdamage;
  }
  return *this;
}

void ScavTrap::attack(const std::string &target) {
 if (m_hitpoints == 0) {
    std::cout << "Can't attack " << target << ", because ScavTrap " << m_name
              << " is dead.\n";
    return;
  }
  if (m_energypoints == 0) {
    std::cout << "Can't attack " << target << ", because ScavTrap " << m_name
              << " has no energy.\n";
    return;
  }
  m_energypoints--;
  std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing "
            << m_attackdamage << " points of damage!\n";
}

void ScavTrap::guardGate() {
  if (m_hitpoints == 0) {
    std::cout << m_name
              << " ScavTrap can't guard gate, because they are dead\n";
    return;
  }

  std::cout << "ScavTrap " << m_name << " ScavTrap is now guarding the gate\n";
}
