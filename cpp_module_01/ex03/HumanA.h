/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:03:40 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 19:14:43 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__
#include "Weapon.h"

class HumanA {
public:
  HumanA(const std::string &name, const Weapon &weapon);
  ~HumanA();
  void attack();

private:
  std::string m_name;
  const Weapon &m_weapon;
};

#endif // __HUMANA_H__
