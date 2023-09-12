/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:04:38 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 19:14:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include <iostream>

HumanA::HumanA(const std::string &name, const Weapon &weapon)
    : m_name(name), m_weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << m_name << " attacks with their " << m_weapon.getType()
            << std::endl;
}
