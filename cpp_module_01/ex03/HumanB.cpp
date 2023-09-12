/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:07:02 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:15:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string &name) : m_name(name), m_weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(const Weapon &weapon) { m_weapon = &weapon; }

void HumanB::attack() {
  if (m_weapon) {
    std::cout << m_name << " attacks with their " << m_weapon->getType()
              << std::endl;
    return;
  }
  std::cout << m_name << " does not have a weapon." << std::endl;
}
