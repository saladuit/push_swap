# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:49:39 by safoh             #+#    #+#              #
#    Updated: 2022/06/12 16:28:12 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makerc/colours.mk
include makerc/main.mk
include makerc/srcs.mk
include makerc/lib.mk
include makerc/headers.mk
include makerc/unit.mk

################################################################################

PROJECT			:=	Push_Swap_Project
NAME			:=	push_swap

CC				:=	gcc
RM				:=	rm -rfv
CFLAGS			=	-Wall -Wextra -Werror $(if $(DEBUG), -g) \
					$(if $(FSAN), -fsanitize=address -g)

################################################################################
all: $(NAME)

$(NAME): SHELL := /bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
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
	$(RM) $(NAME) $(UNIT_TEST) *.gcda *.gcno *.gcov
	@$(MAKE) fclean -C $(LIB_DIR)

re: fclean
	$(MAKE)

tests_run: CFLAGS += --coverage ## Launch tests
tests_run: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(addprefix $(UNIT_SRCS_DIR)/, $(UNIT_SRCS)) -o $(UNIT_TEST) $(LIBFT) $(UNIT_INCLUDE_FLAGS) $(INCLUDE_FLAGS) $(UNIT_LFLAGS)
	./$(UNIT_TEST) -j0
	gcov --no-output $(COVERAGE)

re_tests: fclean
	@$(MAKE) tests_run

valgrind: all ## Launch valgrind
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re tests_run debug fsan valgrind

################################################################################
