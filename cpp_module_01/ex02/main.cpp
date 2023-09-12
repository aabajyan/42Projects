/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:53:54 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 18:13:49 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "&str: " << &str << std::endl;
  std::cout << "strintPTR: " << stringPTR << std::endl;
  std::cout << "&strintREF: " << &stringREF << std::endl;
  std::cout << "*strintPTR: " << *stringPTR << std::endl;
  std::cout << "strintREF: " << stringREF << std::endl;
}
