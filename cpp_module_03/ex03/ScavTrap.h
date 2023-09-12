/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:50:54 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 19:35:37 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_H__
#define __SCAV_TRAP_H__
#include "ClapTrap.h"
#include <string>

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ~ScavTrap();

  ScavTrap &operator=(const ScavTrap &other);

  void attack(const std::string &target);
  void guardGate();
};

#endif // __SCAV_TRAP_H__
