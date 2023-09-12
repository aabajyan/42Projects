/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:22:15 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:13:06 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
  size_t size = 8;
  Zombie *zombie = zombieHorde(size, "horde");
  for (size_t i = 0; i < size; ++i)
    zombie[i].announce();
  delete[] zombie;
  return 0;
}
