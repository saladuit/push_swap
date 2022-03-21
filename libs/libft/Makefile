# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/02/09 17:06:29 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/21 12:43:11 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include ../../Makepretty.mk
include src/libftsrcs.txt

NAME			=	libft.a
CC				:=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				:=	rm -f
SRC_DIR 		:=	./src
INC_DIR 		:=	./include
BUILD_DIR		:=	./build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(LIBFTSRCS:%.c=%.o))

#################################Debug_settings################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = libft_debug.a
endif
ifdef FSAN
CFLAGS	+=	-fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@ar rc $@ $^
	$(DONE_MESSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MESSAGE)

clean:
	@$(RM) $(OBJS)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

fclean: clean
	@$(RM) $(NAME)
	rm -rf *.dSYM
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

re: fclean all

libft_tester: re
	bash tests/libft-war-machine/grademe.sh -d -u $(FILE)

libft_unit_test: re
	$(MAKE) -C ./tests/libft-unit-test f $(FILE)
	cat -e tests/libft-unit-test/result.log

main: all
	$(CC) $(CFLAGS) src/main.c -lft_debug -o libft_gdb
	./libft_gdb

.PHONY: all clean fclean re libft_tester main
