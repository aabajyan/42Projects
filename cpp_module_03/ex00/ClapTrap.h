/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:28:40 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/06 18:03:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_H__
#define __CLAP_TRAP_H__
#include <string>

class ClapTrap {
public:
  ClapTrap();
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  virtual ~ClapTrap();
  ClapTrap &operator=(const ClapTrap &other);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void setAttackDamange(unsigned int damage);

private:
  std::string m_name;
  unsigned int m_hitpoints;
  unsigned int m_energypoints;
  unsigned int m_attackdamage;
};

#endif // __CLAP_TRAP_H__
