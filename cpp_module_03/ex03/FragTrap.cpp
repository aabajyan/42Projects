/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:13:10 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 20:41:44 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  m_hitpoints = 100;
  m_energypoints = 100;
  m_attackdamage = 30;

  std::cout << "FragTrap default has been created\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  m_hitpoints = 100;
  m_energypoints = 100;
  m_attackdamage = 30;

  std::cout << "FragTrap " << m_name << " has been created.\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap " << other.m_name << " has been copied.\n";
}

FragTrap::~FragTrap() { std::cout << "FragTrap " << m_name << " has been destroyed\n"; }

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap" << m_name << " operator assignment called from " << other.m_name << ".\n";
  if (this != &other) {
    m_name = other.m_name;
    m_hitpoints = other.m_hitpoints;
    m_energypoints = other.m_energypoints;
    m_attackdamage = other.m_attackdamage;
  }
  return *this;
}

void FragTrap::highFivesGuys() {
  if (m_hitpoints == 0) {
    std::cout << "FragTrap " << m_name
              << " can't high five, because they are dead\n";
    return;
  }

  std::cout << "FragTrap " << m_name << " high fives guys!\n";
}
