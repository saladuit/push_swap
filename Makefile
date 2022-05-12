# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                        |o_o || |                 #
#                                                      +:+                     #
#    By: saladuit <safoh@student.codam.nl>            +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/13 21:33:38 by saladuit      #+#    #+#                  #
#    Updated: 2022/05/04 18:43:05 by saladuit     \___)=(___/                  #
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
MAIN_OBJ		=	$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

LIB_DIR			=	./libs/libft
LIBFT			:=  $(LIB_DIR)/libft.a
HEADERS			=	$(LIB_DIR)/include/libft.h \
					include/push_swap.h

INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS		:= $(addprefix -L, $(sort $(dir $(USER_LIBS))))

UNIT_TEST		:=	unit-test
UNIT_DIR		:= ./unit_test
UNIT_SRCS_DIR	:=	$(UNIT_DIR)/src/

UNIT_HEADERS	:=	unit_test/include/unit_push_swap.h
UNIT_LFLAGS		:=	-lcriterion
UNIT_OBJS		=	$(UNIT_SRCS:.c=.o)
UNIT_INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(UNIT_HEADERS)))) $(INCLUDE_FLAGS)
# COVERAGE	=	$(SRCS:.c=.gcda)	\
				$(SRCS:.c=.gcno)	\
				$(MAIN:.c=.gcda)	\
				$(MAIN:.c=.gcno)	\
				$(UNIT_SRCS:.c=.gcno)	\
				$(UNIT_SRCS:.c=.gcda)	\
################################################################################
all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

################################################################################

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

clean:
	$(RM) $(OBJS) $(MAIN_OBJ) $(UNIT_TEST_OBJS) $(COVERAGE)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(UNIT_TEST)
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

tests_run: CFLAGS +=-g -fsanitize=address --coverage## Launch tests
tests_run: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(addprefix $(UNIT_SRCS_DIR)/, $(UNIT_SRCS)) -o $(UNIT_TEST) $(LIBFT) $(UNIT_INCLUDE_FLAGS) $(UNIT_LFLAGS)
	./$(UNIT_TEST) -j0

re_tests: fclean tests_run

valgrind: all ## Launch valgrind
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re tests_run debug fsan valgrind
################################################################################
