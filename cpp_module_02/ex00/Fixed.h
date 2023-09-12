/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <arsen.abajyan@pm.me>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:18:01 by aabajyan          #+#    #+#             */
/*   Updated: 2022/07/30 20:00:17 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  ~Fixed();
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(const int raw);

private:
  int m_value;
  static const int s_bits;
};

#endif // __FIXED_H__
