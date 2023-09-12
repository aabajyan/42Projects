/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:13:47 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 17:56:59 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
  Zombie *zombie1 = newZombie("Zombie 1");
  zombie1->announce();
  randomChump("Zombie 2");
  delete zombie1;
  return 0;
}
