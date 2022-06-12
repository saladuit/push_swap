# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/12 17:00:28 by safoh             #+#    #+#              #
#    Updated: 2022/06/12 19:17:15 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../makerc/colours.mk
include ../makerc/makefile.mk
include ../makerc/unit_makefile.mk

NAME			:= ../$(UNIT_TEST)

CC				:=	gcc
RM				:=	rm -rfv
CFLAGS			=	-Wall -Wextra -Werror --coverage -g
UNIT_LFLAGS		:=-lcriterion

all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(UNIT_OBJS)
	$(CC) $(CFLAGS) $^ $(UNIT_LIBS) $(PRODUCTION_OBJS) $(UNIT_LFLAGS) $(UNIT_INCLUDE_FLAGS) -o $(NAME)

../$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(UNIT_HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(UNIT_INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(UNIT_OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
