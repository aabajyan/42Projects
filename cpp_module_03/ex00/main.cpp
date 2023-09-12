/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:28:30 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 18:04:40 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int main() {
  ClapTrap ct("Dave");
  ClapTrap ct2(ct);
  ct2.attack("Bob");
  ct2.setAttackDamange(20);
  ct2.attack("Bob");
  ct2.takeDamage(5);
  ct2.beRepaired(10);
  ct2.takeDamage(9999);
  ct2.beRepaired(100);

  for (size_t i = 0; i < 11; ++i)
    ct.attack("James");
  ct.beRepaired(100);

  return 0;
}
