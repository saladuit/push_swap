# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 11:07:01 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/21 12:33:11 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include makepretty.mk

NAME		=	push_swap
CC			:=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			:=	rm -f
MAIN		=	main.c
SRCS		=	push_swap.c
SRC_DIR		=	./src
INC_DIR		=	./include
BUILD_DIR	=	./build
OBJS		=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
LIB_DIR		=	libs/libft
LIBFT		:= $(LIB_DIR)/libft.a

#################################Debug_settings#################################
ifdef DEBUG
	CFLAGS	+=	-g
	NAME = push_swap_debug
	LIBFT = $(LIB_DIR)/libft_debug.a
endif
ifdef FSAN
	CFLAGS	+=	-fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $^ -o $(NAME)
	$(DONE_MESSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	$(COMPILE_MESSAGE)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

fclean: clean
	$(RM) $(NAME) push_swap_debug
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf push_swap_debug.dSYM
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

re: fclean all
	$(MAKE) re -C $(LIB_DIR)
	$(EMPTY_MESSAGE)
	$(RESET_MESSAGE_3)
	$(RESET_MESSAGE_2)
	$(RESET_MESSAGE_1)

push_swap_tester: all
	bash push_swap_tester/basic_test.sh

.PHONY: all clean fclean push_swap_tester re
