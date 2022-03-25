# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/02/09 17:06:29 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/25 10:40:23 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include ../../makerc/colours.mk
include ../../makerc/utils.mk
include ../../makerc/libftsrcs.mk

################################################################################
PROJECT			=	Libft
NAME			=	$(if $(or $(DEBUG), $(FSAN)), libft_debug.a, libft.a)

CC				:=	gcc
CFLAGS			=	-Wall -Wextra -Werror $(if $(DEBUG), -g) $(if $(FSAN), -fsanitize=address -g)
RM				:=	rm -rf

SRC_DIR 		:=	./src
BUILD_DIR		:=	./build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
HEADERS			=	include/libft.h
INCLUDE_FLAGS	=	$(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS		+=	$(addprefix -L, $(sort $(dir $(USER_LIBS))))


ifndef PROJECT_SPACING
	export PROJECT_SPACING := 7
endif
################################################################################
all: $(NAME)

$(NAME): $(OBJS)
	@$(call print_prefix,"$(PROJECT)","make")
	@ar rc $@ $^
	@$(call print_prefix,"$(PROJECT)","make")
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)
	@printf "$(CLEAR_REST_OF_LINE)\r"

################################################################################
clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) *.a *.dSYM $(MAKE_TXT)

re: fclean all

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

libft_tester: re
	bash tests/libft-war-machine/grademe.sh -d -u $(FILE)

libft_unit_test: re
	$(MAKE) -C ./tests/libft-unit-test f $(FILE)
	cat -e tests/libft-unit-test/result.log

main: all
	$(CC) $(CFLAGS) src/main.c -lft_debug -o libft_gdb
	./libft_gdb

.PHONY: all clean fclean re libft_tester main
################################################################################
