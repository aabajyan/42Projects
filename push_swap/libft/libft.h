/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:49:27 by aabajyan          #+#    #+#             */
/*   Updated: 2021/06/28 15:26:26 by aabajyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

extern void		*ft_memset(void *buffer, int c, size_t size);
extern void		*ft_memcpy(void *dest, const void *src, size_t n);
extern void		*ft_memmove(void *dest, const void *src, size_t n);
extern void		*ft_memccpy(void *d, const void *s, const char c, size_t n);
extern int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
extern void		*ft_memchr(const void *ptr, int value, size_t num);
extern void		ft_bzero(void *buffer, size_t size);

extern char		*ft_strnstr(const char *h, const char *n, size_t l);
extern char		*ft_strrchr(const char *str, int chr);
extern size_t	ft_strlcpy(char *dst, const char *src, size_t n);
extern size_t	ft_strlcat(char *dst, const char *src, size_t n);
extern int		ft_strncmp(const char *str1, const char *str2, size_t n);
extern size_t	ft_strlen(const char *str);
extern char		*ft_strrchr(const char *str, int c);
extern char		*ft_strchr(const char *str, int c);

extern int		ft_isdigit(int c);
extern int		ft_isalpha(int c);
extern int		ft_isalnum(int c);
extern int		ft_isprint(int c);
extern int		ft_isascii(int c);

extern int		ft_toupper(int c);
extern int		ft_tolower(int c);

extern int		ft_atoi(const char *str);

extern void		*ft_calloc(size_t el_num, size_t el_size);
extern char		*ft_strdup(const char *s);

extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern char		*ft_strjoin(char const *s1, char const *s2);
extern char		*ft_strtrim(char const *s1, char const *set);
extern char		**ft_split(char const *s, char c);
extern char		*ft_itoa(int n);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putstr_fd(char *s, int fd);
extern void		ft_putendl_fd(char *s, int fd);
extern void		ft_putnbr_fd(int n, int fd);
#endif
