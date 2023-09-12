/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:50:32 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 16:27:14 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <string>

class Contact {
public:
  Contact(void);
  ~Contact(void);

  void set_first_name(const std::string &first_name);
  void set_last_name(const std::string &last_name);
  void set_nickname(const std::string &nickname);
  void set_phone(const std::string &phone);
  void set_secret(const std::string &secret);

  const std::string &get_first_name(void) const;
  const std::string &get_last_name(void) const;
  const std::string &get_nickname(void) const;
  const std::string &get_phone(void) const;
  const std::string &get_secret(void) const;

private:
  std::string m_first_name;
  std::string m_last_name;
  std::string m_nickname;
  std::string m_phone;
  std::string m_secret;
};

#endif // __CONTACT_H__
