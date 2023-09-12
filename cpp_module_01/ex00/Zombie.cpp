/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:11:42 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 17:57:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie(const std::string &name) : m_name(name) {
  std::cout << "Zombie `" << m_name << "` is been created\n";
}

Zombie::~Zombie() {
  std::cout << "Zombie `" << m_name << "` is been destroyed\n";
}

void Zombie::announce(void) {
  std::cout << m_name << ": BraiiiiiiinnnzzzZ...\n";
}
