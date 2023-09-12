/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:06:26 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:15:53 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__
#include "Weapon.h"

class HumanB {
public:
  HumanB(const std::string &name);
  ~HumanB();
  void attack();
  void setWeapon(const Weapon &weapon);

private:
  std::string m_name;
  const Weapon *m_weapon;
};

#endif // __HUMANB_H__
