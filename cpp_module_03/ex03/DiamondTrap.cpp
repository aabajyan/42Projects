/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:21:49 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 20:21:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include <iostream>

DiamondTrap::DiamondTrap() : m_name("Unknown") {
  std::cout << "DiamondTrap default has been created\n";
 
  ClapTrap::m_name = "Unknown_clap_name";
  m_hitpoints = FragTrap::m_hitpoints;
  m_energypoints = ScavTrap::m_energypoints;
  m_attackdamage = FragTrap::m_attackdamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : m_name(name) {
  std::cout << "DiamondTrap " << m_name << " has been created.\n";

  ClapTrap::m_name = name + "_clap_name";
  m_hitpoints = FragTrap::m_hitpoints;
  m_energypoints = ScavTrap::m_energypoints;
  m_attackdamage = FragTrap::m_attackdamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), m_name(other.m_name) {
      std::cout << "DiamondTrap " << other.m_name << " has been copied.\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << m_name << " has been destroyed\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap" << m_name << " operator assignment called from " << other.m_name << ".\n";
  if (this != &other) {
    ClapTrap::m_name = other.ClapTrap::m_name;
    m_name = other.m_name;
    m_hitpoints = other.m_hitpoints;
    m_energypoints = other.m_energypoints;
    m_attackdamage = other.m_attackdamage;
  }
  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
  std::cout << "I am " << m_name << ", my ClapTrap name is " << ClapTrap::m_name
            << "\n";
}
