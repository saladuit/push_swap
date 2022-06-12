# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 13:49:39 by safoh             #+#    #+#              #
#    Updated: 2022/06/12 19:20:47 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include makerc/colours.mk
include makerc/makefile.mk
include makerc/unit_makefile.mk

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
	$(RM) $(OBJS) $(MAIN_OBJ) *.gcda *.gcno *.gcov
	@$(MAKE) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(UNIT_DIR)

fclean: clean
	$(RM) $(NAME) $(UNIT_TEST)
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) fclean -C $(UNIT_DIR)

re: fclean
	$(MAKE)

tests_run: CFLAGS +=-g --coverage ## Launch tests
tests_run: $(LIBFT) $(OBJS)
	$(MAKE) -C $(UNIT_DIR)
	./$(UNIT_TEST)
	gcov -n $(COVERAGE) -o=build

re_tests: fclean
	@$(MAKE) tests_run

valgrind: all ## Launch valgrind
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re tests_run debug fsan valgrind

################################################################################
