/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:20:25 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 19:31:22 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombieHorde = new Zombie[N];
  for (int i = 0; i < N; ++i)
    zombieHorde[i].set_name(name);
  return zombieHorde;
}
