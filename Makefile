# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: saladuit <safoh@student.codam.nl>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/13 21:33:38 by saladuit      #+#    #+#                  #
#    Updated: 2022/04/13 22:11:06 by saladuit      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include makerc/main.mk
include makerc/srcs.mk
include makerc/colours.mk
include makerc/unit_srcs.mk

PROJECT			:=	Push-Swap
NAME			:=	push_swap

CC				:=	gcc
RM				:=	rm -rfv
CFLAGS			=	-Wall -Wextra -Werror $(if $(DEBUG), -g) \
					$(if $(FSAN), -fsanitize=address -g)

SRC_DIR			:=	./src
BUILD_DIR		:=	./build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
MAIN_OBJS		=	$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

LIB_DIR			=	./libs/libft
LIBFT			:=  $(LIB_DIR)/libft.a
HEADERS			=	$(LIB_DIR)/include/libft.h \
					include/push_swap.h

INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS		:= $(addprefix -L, $(sort $(dir $(USER_LIBS))))

UNIT_TEST		:=	unit-test
UNIT_DIR		:= ./unit_test
UNIT_SRC_DIR	:=	$(UNIT_DIR)/src/

UNIT_HEADERS	:=	unit_test/include/unit_push_swap.h
UNIT_LFLAGS		:=	-lcriterion
UNIT_OBJS		:=	$(addprefix $(BUILD_DIR)/, $(UNIT_SRCS:%.c=%.o))
################################################################################
all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(OBJS) $(MAIN_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

################################################################################
clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) push_swap_debug *.dSYM
	@$(MAKE) fclean -C $(LIB_DIR)

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

re: fclean all

tests_run: CFLAGS +=-g -fsanitize=address --coverage## Launch tests
tests_run: $(LIBFT) $(OBJS) $(UNIT_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(UNIT_OBJS) -o $(UNIT_TEST) $(LIBFT) $(INCLUDE_FLAGS) $(UNIT_LFLAGS)
	./$(UNIT_TEST) -j0

.PHONY: all clean fclean re push_swap_tester debug fsan
################################################################################
