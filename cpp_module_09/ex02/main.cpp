/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:28:18 by aabajyan          #+#    #+#             */
/*   Updated: 2023/03/17 18:14:31 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {

  if (argc < 2) {
    std::cout << "Usage: ./PmergeMe [...numbers]" << std::endl;
    return 0;
  }

  try {
    PmergeMe app(argc - 1, argv + 1);
    app.sort_and_print();
  } catch (const std::exception &ex) {
    std::cout << ex.what() << std::endl;
    return 1;
  }

  return 0;
}
