# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                        |o_o || |                 #
#                                                      +:+                     #
#    By: safoh <safoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/11 14:27:07 by safoh         #+#    #+#                  #
#    Updated: 2021/09/28 16:05:55 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

NAME			:=	push_swap
CC				:=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				:=	rm -f

#################################Project_files##################################
# SRCS			=	RESOURCES
# SRC_DIR		=	SOURCES DIRECTORY
# INC_DIR		=	INCLUDES DIRECTORY
# BUILD_DIR		=	BUILD DIRECTORY
# OBJS			=	OBJECTS
# LIB			=	LIBFT LIBRARY

SRCS			:=	push_swap.c
SRC_DIR			:=	./src
INC_DIR			:=	./include
BUILD_DIR		:=	./build
OBJS			:=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
PRINTF			:= libs/ft_printf/libftprintf.a
################################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run "make ft_printf_test" to test the lilbftprintf.a"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings#################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = libftprintf_debug.a
LIB = libs/libft/libft_debug.a
endif
ifdef FSAN
CFLAGS	+=	-fsanitize=address
endif
ifdef SPEED
CFLAGS	+=	-Ofast
endif
ifdef ERROR
CFLAGS	+=	-D ELABORATE_ERR=1
endif
ifdef LEAKS
CFLAGS	+=	-D LEAKS=1
endif
ifdef CRITERION
CFLAGS	+=	-lcriterion
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@echo "\n"
	ar rcs $@ $^
	ar -q $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	@echo $(MESSSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	@printf $(C_MESSAGE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C libs/libft/

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libs/libft/
	@echo "Objects libft cleaned"

fclean: clean
	$(RM) $(NAME) printf_gdb
	$(MAKE) fclean -C libs/libft/
	@echo "Library printf cleaned"

re: fclean all

ft_printf_test: all
	$(MAKE) quiet -C test/ft_printf_test/

ft_printf_tester: all
	cd test/ft_printf_tester; sh test m

main:
	gcc src/main.c -L. -lftprintf_debug -g -o printf_gdb

.PHONY: all clean fclean ft_printf_test fr_printf_tester maie re
