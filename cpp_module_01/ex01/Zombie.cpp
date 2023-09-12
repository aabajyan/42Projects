/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:11:42 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:11:31 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(const std::string &name) : m_name(name) {
  std::cout << "Zombie `" << m_name << "` is been created\n";
}

Zombie::~Zombie() {
  std::cout << "Zombie `" << m_name << "` is been destroyed\n";
}

void Zombie::announce() { std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n"; }

const std::string &Zombie::name() const { return m_name; }

void Zombie::set_name(const std::string &name) { m_name = name; }
