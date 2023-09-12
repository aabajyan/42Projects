/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:28:18 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/14 21:34:55 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {

  if (argc <= 1) {
    std::cout << "Usage ./RPN [Input]" << std::endl;
    return 0;
  }

  RPN rpn = RPN(std::string(argv[1]));

  try {
    std::cout << rpn.calculate() << std::endl;
  } catch (const std::exception &error) {
    std::cout << error.what() << std::endl;
  }

  return 0;
}
