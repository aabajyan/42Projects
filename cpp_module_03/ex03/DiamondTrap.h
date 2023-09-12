/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:21:54 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 20:16:15 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMOND_TRAP_H__
#define __DIAMOND_TRAP_H__
#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap();
  DiamondTrap(const std::string &name);
  DiamondTrap(const DiamondTrap &other);
  ~DiamondTrap();

  DiamondTrap &operator=(const DiamondTrap &other);

  void attack(const std::string &target);
  void whoAmI() const;

private:
  std::string m_name;
};

#endif // __DIAMOND_TRAP_H__
