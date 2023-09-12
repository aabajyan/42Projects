/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:30:22 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/18 14:44:05 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "ICharacter.h"
#include <string>

#define CHARACTER_INVENTORY_SIZE 4

class Character : public ICharacter {
public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);
  ~Character();

  Character &operator=(const Character &other);

  const std::string &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string m_name;
  AMateria *m_inventory[CHARACTER_INVENTORY_SIZE];
  int m_size;
};

#endif // __CHARACTER_H__
