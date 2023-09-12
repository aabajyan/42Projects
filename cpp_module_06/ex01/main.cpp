/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:07:09 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:21:15 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data {
  int n;
};

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data *deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }

int main() {

  Data *test = new Data;
  test->n = 42;

  uintptr_t ptr = serialize(test);
  Data *data = deserialize(ptr);

  std::cout << "serialized: " << ptr << "\ndeserialized: " << test << "\n";

  std::cout << "original value: " << test->n
            << "\ndeserialized value: " << data->n << "\n";

  delete test;

  return 0;
}
