/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:35:46 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 17:20:53 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
#include "Contact.h"

#define PHONEBOOK_MAX_SIZE 8

class PhoneBook {
public:
  PhoneBook();
  void add();
  void print(size_t index);
  void search();

private:
  bool is_empty(const std::string &src);
  bool obtain_value(std::string& dest, const std::string &name);
  bool is_numeric(const std::string &src);
  void print_formatted(const std::string &src);

private:
  size_t m_index;
  size_t m_size;
  Contact m_data[PHONEBOOK_MAX_SIZE];
};

#endif // __PHONEBOOK_H__
