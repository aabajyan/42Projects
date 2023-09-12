# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 13:16:50 by aabajyan          #+#    #+#              #
#    Updated: 2021/05/13 00:25:39 by aabajyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME = $(shell uname)
NAME = so_long
CC = gcc
MAKE = make
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft
LDFLAGS = $(CFLAGS) -L./libft -lft
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

ifeq ($(UNAME), Linux)
	CFLAGS  += -I/usr/X11/include
	LDFLAGS += -L/usr/X11/lib -lmlx -lXext -lX11
endif

ifeq ($(UNAME), Darwin)
	CFLAGS	+= -Imlx
	LDFLAGS	+= -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C libft
	$(MAKE) -C mlx
	@mkdir -p $(@D)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)
	$(MAKE) -C libft all
	$(MAKE) -C mlx all

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -DDEBUG -g -O0
debug: re

.PHONY: clean re fclean all
