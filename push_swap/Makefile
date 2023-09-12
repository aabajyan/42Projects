# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:34:57 by aabajyan          #+#    #+#              #
#    Updated: 2021/08/15 16:47:51 by aabajyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft
LDFLAGS = $(CFLAGS) -lft -L./libft

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:src/%.c=obj/%.o)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C libft
	@mkdir -p $(@D)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

all: $(NAME) $(NAME_CHECKER)
	$(MAKE) -C libft all

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: clean re fclean all
