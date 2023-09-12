# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabajyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:34:57 by aabajyan          #+#    #+#              #
#    Updated: 2021/08/12 17:15:22 by aabajyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include

# General
SRCS = 	src/utils.c \
		src/utils_fd.c
OBJS = $(SRCS:src/%.c=obj/%.o)

# Client
CLIENT = client
CLIENT_SRCS = $(SRCS) src/client.c
CLIENT_OBJS = $(OBJS) obj/client.o

$(CLIENT): $(OBJ_DIR) $(CLIENT_OBJS)
	@mkdir -p $(@D)
	$(CC) $(CLIENT_OBJS) -o $@ $(CFLAGS)

# Server
SERVER = server
SERVER_SRCS = $(SRCS) src/server.c
SERVER_OBJS = $(OBJS) obj/server.o

$(SERVER): $(OBJ_DIR) $(SERVER_OBJS)
	@mkdir -p $(@D)
	$(CC) $(SERVER_OBJS) -o $@ $(CFLAGS)

# General object files
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Misc
all: $(SERVER) $(CLIENT)

clean:
	rm -f $(OBJS) obj/server.o obj/client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: clean re fclean all
