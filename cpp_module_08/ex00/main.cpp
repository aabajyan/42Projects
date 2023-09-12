/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:20:11 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:54:24 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> values;
  std::vector<int>::iterator iter;

  std::cout << "Values:\n";
  for (int i = 0; i < 10; ++i) {
    values.push_back(i * i);
    std::cout << values[i] << "\n";
  }

  std::cout << "Values:\n";
  iter = easyfind(values, 4);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  iter = easyfind(values, 2);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  iter = easyfind(values, 1000);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  iter = easyfind(values, -4);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  iter = easyfind(values, 81);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  iter = easyfind(values, 64);
  if (iter == values.end())
    std::cout << "iter: Not found\n";
  else
    std::cout << "iter: " << *iter << "\n";

  return 0;
}
