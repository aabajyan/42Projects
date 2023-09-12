/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 00:24:14 by aabajyan          #+#    #+#             */
/*   Updated: 2022/08/15 12:35:32 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __A_MATERIA_H__
#define __A_MATERIA_H__
#include <string>

class ICharacter;
class AMateria {
public:
  AMateria();
  AMateria(const std::string &type);
  virtual ~AMateria();

  const std::string &getType() const; // return the materia type

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string m_type;
};

#endif // __A_MATERIA_H__
