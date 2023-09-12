/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:28:30 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 20:40:48 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

int main() {
  std::cout << "\n\n!!!!! BEGIN EX00 !!!!!\n\n";
  {
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
  }
  std::cout << "\n\n!!!!! END EX00 !!!!!\n\n";

  std::cout << "\n\n!!!!! BEGIN EX01 !!!!!\n\n";
  {
    std::cout << "=== BEGIN CONSTRUCTOR ===\n";
    ClapTrap ct;
    ScavTrap st3("Jim");
    ScavTrap st1;
    ScavTrap st2("Bob");
    std::cout << "=== END CONSTRUCTOR ===\n";

    std::cout << "\n";

    std::cout << "=== BEGIN ATTACK ===\n";
    ct.attack("Bob");
    st1.attack("Dave");
    st3.attack("James");
    st2.attack("Felix");
    std::cout << "=== END ATTACK ===\n";

    std::cout << "\n";

    std::cout << "=== BEGIN TAKE DAMAGE ===\n";
    ct.takeDamage(80);
    st3.takeDamage(50);
    st3.takeDamage(50);
    st2.takeDamage(5);
    std::cout << "=== END TAKE DAMAGE ===\n";

    std::cout << "\n";

    std::cout << "=== BEGIN TAKE DAMAGE ===\n";
    ct.beRepaired(1000);
    st3.beRepaired(1);
    st2.beRepaired(5);
    std::cout << "=== END TAKE DAMAGE ===\n";

    std::cout << "\n";

    std::cout << "=== BEGIN TAKE DAMAGE ===\n";
    st3.guardGate();
    st2.guardGate();
    std::cout << "=== END TAKE DAMAGE ===\n";

    std::cout << "\n";
  }
  std::cout << "\n\n!!!!! END EX01 !!!!!\n\n";

  return 0;
}
