/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 22:04:34 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:21:09 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./convert [value]\n";
    return 0;
  }

  Convert convert = Convert(std::string(argv[1]));
  std::cout << convert << "\n";
  return 0;
}
