# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 17:58:29 by aabajyan          #+#    #+#              #
#    Updated: 2021/04/08 17:10:02 by aabajyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_NAME = libft/libft.a
OBJ_DIR = obj

CC = gcc
CFLAGS = -I. -I./libft -Wall -Wextra -Werror
AR = ar
MAKE = make

SRCS = $(wildcard src/*.c)
SUBDIRS = libft/
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C $(SUBDIRS)
	cp libft/libft.a $@
	$(AR) -rcs $@ $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean: $(SUBDIRS) clean
	rm -f $(NAME)

clean: $(SUBDIRS)
	rm -f $(OBJS)

re: $(SUBDIRS) fclean all

all: $(NAME)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: clean fclean re all $(SUBDIRS)
