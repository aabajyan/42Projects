/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:42:24 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:33:27 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  for (int i = 1; i < argc; ++i)
    for (int j = 0; argv[i][j] != '\0'; ++j)
      std::cout << static_cast<char>(std::toupper(argv[i][j]));
  std::cout << std::endl;
  return 0;
}
