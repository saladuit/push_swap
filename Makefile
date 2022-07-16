# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/07/07 17:49:38 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/07/16 19:42:44 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include makerc/colours.mk
include makerc/makefile.mk
include makerc/unit_makefile.mk

################################################################################

NAME			:=push_swap

CC				:=gcc
RM				:=rm -rfv
CFLAGS			=-Wall -Wextra -Werror$(if $(DEBUG), -g -fsanitize=address)\
				 $(if $(MALLOC), -g)

################################################################################
all: $(NAME)

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

################################################################################

clean:
	@$(RM) $(OBJS) $(MAIN_OBJ) $(addprefix $(BUILD_DIR)/, $(COVERAGE))
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(UNIT_DIR)

fclean: clean
	@$(RM) $(NAME) $(UNIT_TEST)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(UNIT_DIR)

re: fclean
	@$(MAKE)

tests_run: CFLAGS +=-g --coverage ## Launch tests
tests_run: $(OBJS) $(LIBFT)
	@$(MAKE) -C $(UNIT_DIR)
	@./$(UNIT_TEST) -j0
	@gcov $(addprefix build/, $(SRCS)) -n -b -f -a 

re_tests: fclean
	@$(MAKE) tests_run

debug:
	@$(MAKE) DEBUG=1

rebug: fclean
	@$(MAKE) debug

re_malloc_test: fclean
	@$(MAKE) malloc_test

malloc_test: $(OBJS) $(MAIN_OBJ) $(LIBFT)
	@$(MAKE) MALLOC=1
	$(CC) $(CFLAGS) $^ -fsanitize=undefined -rdynamic -o $@ $(INCLUDE_FLAGS) -L. -lmallocator

valgrind: all ## Launch valgrind
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re tests_run debug rebug valgrind malloc_test \
	re_malloc_test

################################################################################
