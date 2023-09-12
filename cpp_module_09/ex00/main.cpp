/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:29:45 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 18:14:39 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: ./btc [path]" << std::endl;
    return 0;
  }

  try {
    BitcoinExchange btc;
    btc.calculate(std::string(argv[1]));
  } catch (const std::exception &error) {
    std::cout << error.what() << std::endl;
    return 1;
  }

  return 0;
}
