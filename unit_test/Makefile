# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 10:11:56 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/21 15:01:03 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include	../makerc/utils.mk
include ../makerc/colours.mk
include	../src/pushsrcs.txt
include	src/testsrcs.txt

NAME		:=	pushtest
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -coverage
CRITERION	:=	-lcriterion
RM			=	rm -fv
OBJS		=	$(addprefix $(BUILD_DIR)/, $(TESTSRCS:%.c= %.o))
OBJS		+=	$(addprefix $(BUILD_DIR)/, $(PUSHSRCS:%.c= %.o))
SRC_DIR		=	./src
PSRC_DIR	=	../src
BUILD_DIR	=	./build
LIB_DIR		:=	../libs/libft
LIBFT		:=	$(LIB_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(CRITERION) $(OBJS) $(LIBFT) -o $@
	$(DONE_MESSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	@$(CC) -c $< $(CFLAGS) -o $@
	$(COMPILE_MESSAGE)

$(BUILD_DIR)/%.o: $(PSRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< $(CFLAGS) -o $@
	$(COMPILE_MESSAGE)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

clean:
	@$(RM) $(OBJS)
	$(MAKE) clean -C $(LIB_DIR)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) fclean -C $(LIB_DIR)
	$(MESSY_MESSAGE)
	$(DONE_MESSAGE)

re: fclean all
	$(MAKE) -C $(LIB_DIR)
	$(EMPTY_MESSAGE)
	$(RESET_MESSAGE_3)
	$(RESET_MESSAGE_2)
	$(RESET_MESSAGE_1)

.PHONY: all clean fclean re
