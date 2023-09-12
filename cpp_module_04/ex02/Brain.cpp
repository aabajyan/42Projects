/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:50:49 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 02:11:00 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.h"
#include <iostream>

Brain::Brain() {
  for (size_t i = 0; i < IDEA_SIZE; ++i)
    m_ideas[i] = "idea";
  std::cout << "Brain::Brain() called\n";
}

Brain::Brain(const std::string &idea) {
  for (size_t i = 0; i < IDEA_SIZE; ++i)
    m_ideas[i] = idea + " string";
  std::cout << "Brain::Brain(const std::string &idea) called\n";
}

Brain::Brain(const Brain &other) {
  std::cout << "Brain::Brain(const Brain &other) called\n";
  for (size_t i = 0; i < IDEA_SIZE; ++i)
    m_ideas[i] = other.m_ideas[i] + " copied";
}

Brain::~Brain() { std::cout << "Brain::~Brain() called\n"; }

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain &Brain::operator=(const Brain &other) called\n";
  if (this != &other)
    for (size_t i = 0; i < IDEA_SIZE; ++i)
      m_ideas[i] = other.m_ideas[i] + " assigned";
  return *this;
}

const std::string *Brain::getIdeas() const { return m_ideas; }

const std::string &Brain::getIdea() const { return m_ideas[0]; }
