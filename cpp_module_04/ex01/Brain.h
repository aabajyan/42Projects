/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:49:02 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/19 02:10:35 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
#define __BRAIN_H__
#include <string>

#define IDEA_SIZE 100

class Brain {
public:
  Brain();
  Brain(const std::string &idea);
  Brain(const Brain &other);
  ~Brain();

  Brain &operator=(const Brain &other);

  const std::string *getIdeas() const;
  const std::string &getIdea() const;

private:
  std::string m_ideas[IDEA_SIZE];
};

#endif // __BRAIN_H__
