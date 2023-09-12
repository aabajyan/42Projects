/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:12:03 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/01 17:38:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_H__
#define __FRAG_TRAP_H__
#include "ClapTrap.h"
#include <string>

class FragTrap : virtual public ClapTrap {
public:
  FragTrap();
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  ~FragTrap();

  FragTrap &operator=(const FragTrap &other);
  void highFivesGuys();
};

#endif // __FRAG_TRAP_H__
