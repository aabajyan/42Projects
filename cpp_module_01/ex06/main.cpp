/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:16:23 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 19:22:18 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.h"

int karen_translate(const std::string &type) {
  static std::string levels[KAREN_FUNCTION_COUNT] = {"DEBUG", "INFO", "WARNING",
                                                     "ERROR"};
  for (int i = 0; i < KAREN_FUNCTION_COUNT; i++)
    if (levels[i] == type)
      return i;
  return -1;
}

void karen_filter(const std::string &type, Karen &karen) {
  switch (karen_translate(type)) {
  case 0:
    karen.complain("DEBUG");
    // fall through
  case 1:
    karen.complain("INFO");
    // fall through
  case 2:
    karen.complain("WARNING");
    // fall through
  case 3:
    karen.complain("ERROR");
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]\n";
    break;
  }
}

int main(int argc, char **argv) {
  Karen karen;
  if (argc != 2) {
    std::cout << "[ Probably complaining abut insignificant problems ]\n";
    return 0;
  }

  karen_filter(std::string(argv[1]), karen);
  return 0;
}
