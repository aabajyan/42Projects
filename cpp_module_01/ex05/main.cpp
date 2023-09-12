/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:16:23 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:24:23 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.h"

int main() {
  Karen le_karen;

  le_karen.complain("DEBUG");
  le_karen.complain("INFO");
  le_karen.complain("WARNING");
  le_karen.complain("ERROR");
  return 0;
}
