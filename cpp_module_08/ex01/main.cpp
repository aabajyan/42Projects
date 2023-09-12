/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:53:29 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/23 19:49:52 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <cstdlib>
#include <iostream>
#include <list>
#include <array>

int main() {

  std::srand(time(NULL));

  {
    Span s(5);
    s.addNumber(8);
    s.addNumber(16);
    s.addNumber(32);
    s.addNumber(64);
    s.addNumber(128);
    std::cout << "Shortest Span: " << s.shortestSpan()
              << "\nLongest Span: " << s.longestSpan() << "\n";
    try {
      s.addNumber(256);
    } catch (const std::exception &e) {
      std::cout << "1: " << e.what() << "\n";
    }
  }

  try {
    Span s(1);
    s.addNumber(8);
    s.addNumber(8);
  } catch (const std::exception &e) {
    std::cout << "2: " << e.what() << "\n";
  }

  {
    std::vector<int> vector;
    vector.reserve(10000);
    for (size_t i = 0; i < 10000; ++i)
      vector.push_back(std::rand());
    Span massive(10000);
    massive.addNumber(vector.begin(), vector.end());
    std::cout << "Shortest Span: " << massive.shortestSpan()
              << "\nLongest Span: " << massive.longestSpan() << "\n";
  }


  {
    std::list<int> other_type;
    other_type.push_back(2);
    other_type.push_back(4);
    other_type.push_back(6);
    other_type.push_back(8);

    Span span(4);
    span.addNumber(other_type.begin(), other_type.end());
    std::cout << "Shortest Span: " << span.shortestSpan()
              << "\nLongest Span: " << span.longestSpan() << "\n";
  }

  {
    std::array<int, 4> other_type = {3, 6, 9, 12};
    Span span(4);
    span.addNumber(other_type.begin(), other_type.end());
    std::cout << "Shortest Span: " << span.shortestSpan()
              << "\nLongest Span: " << span.longestSpan() << "\n";
    try {
      span.addNumber(4);
    } catch (std::exception &e) {
      std::cout << "3: " << e.what() << "\n";
    }
  }

  {
    try {
      std::array<int, 5> too_long = {3, 6, 9, 12, 15};
      Span span(4);
      span.addNumber(too_long.begin(), too_long.end());
    } catch (std::exception &e) {
      std::cout << "4: " << e.what() << "\n";
    }
  }

  // From subject
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  }

  return 0;
}
