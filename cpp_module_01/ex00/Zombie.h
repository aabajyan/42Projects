/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:07:58 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 17:57:07 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>
#include <string>

class Zombie {
public:
  Zombie(const std::string &name);
  ~Zombie();
  void announce(void);

private:
  std::string m_name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif // __ZOMBIE_H__
