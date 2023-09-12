/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:58:55 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:16:04 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__
#include <string>

class Weapon {
public:
  Weapon();
  Weapon(const std::string &type);
  ~Weapon();
  const std::string &getType() const;
  void setType(const std::string &type);

private:
  std::string m_type;
};

#endif // __WEAPON_H__
