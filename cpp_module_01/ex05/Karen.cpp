/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:18:07 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:24:30 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.h"

Karen::Karen(void) { std::cout << "Another day, another Karen\n"; }

Karen::~Karen(void) { std::cout << "And she's gone!\n"; }

void Karen::debug(void) {
  std::cout << "[DEBUG] I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger.I "
               "really do !\n";
}

void Karen::info(void) {
  std::cout << "[INFO] cannot believe adding extra bacon costs more money. You "
               "didn’t put enough bacon in my burger! If you did, I wouldn’t "
               "be asking for more!\n";
}

void Karen::warning(void) {
  std::cout << "[WARNING] I think I deserve to have some extra bacon for free. "
               "I’ve been coming "
               "for years whereas you started working here since last month.\n";
}

void Karen::error(void) {
  std::cout
      << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void Karen::complain(std::string level) {
  static void (Karen::*func[KAREN_FUNCTION_COUNT])(void) = {
      &Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
  static std::string levels[KAREN_FUNCTION_COUNT] = {"DEBUG", "INFO", "WARNING",
                                                     "ERROR"};
  for (size_t i = 0; i < KAREN_FUNCTION_COUNT; ++i)
    if (levels[i] == level) {
      (this->*func[i])();
      break;
    }
}
