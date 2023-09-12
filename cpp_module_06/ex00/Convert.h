/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:53:51 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/20 18:20:50 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERT_H__
#define __CONVERT_H__
#include <exception>
#include <iostream>
#include <string>

class Convert {
public:
  Convert(const std::string &value);
  Convert(const Convert &other);
  ~Convert();
  Convert &operator=(const Convert &other);

  const std::string &get_value() const;
  void set_value(const std::string &value);

  char to_char() const;
  int to_int() const;
  float to_float() const;
  double to_double() const;

private:
  Convert();

  class ImplossibleException : public std::exception {
    const char *what() const throw();
  };

  class NonDisplayableException : public std::exception {
    const char *what() const throw();
  };

private:
  std::string m_value;
};

std::ostream &operator<<(std::ostream &os, const Convert &convert);

#endif // __CONVERT_H__
