/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:00:28 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:16:01 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include <string>

Weapon::Weapon() {}

Weapon::Weapon(const std::string &type) : m_type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const { return m_type; }

void Weapon::setType(const std::string &type) { m_type = type; }
