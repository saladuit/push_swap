# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                        |o_o || |                 #
#                                                      +:+                     #
#    By: safoh <safoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/11 14:27:07 by safoh         #+#    #+#                  #
#    Updated: 2022/03/02 17:43:35 by safoh        \___)=(___/                  #
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

SRCS			:=	main.c
SRC_DIR			:=	./src
INC_DIR			:=	./include
BUILD_DIR		:=	./build
OBJS			:=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
PRINTF			:= libs/ft_printf/libft.a
################################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run "make push_swap_tester" to test the push_swap"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings#################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = push_swap_debug
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
	gcc $^ -o $(NAME)
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
	@echo "Objects cleaned"

fclean: clean
	$(RM) $(NAME) push_swap_gdb
	$(MAKE) fclean -C libs/libft/
	rm -rf printf_gdb.dSYM
	@echo "Files cleaned"

re: fclean all

push_swap_tester: all
	bash push_swap_tester/basic_test.sh

.PHONY: all clean fclean push_swap_tester re
