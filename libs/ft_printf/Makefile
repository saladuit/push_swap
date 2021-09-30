# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                        |o_o || |                 #
#                                                      +:+                     #
#    By: safoh <safoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/11 14:27:07 by safoh         #+#    #+#                  #
#    Updated: 2021/09/28 16:14:35 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

NAME			:=	libftprintf.a
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

SRCS			:=	ft_printf.c ft_printpct.c ft_printpnt.c ft_printhe_x.c \
		ft_printhex.c ft_printudec.c ft_printdec.c ft_printstr.c ft_cnvspc.c \
		ft_printchr.c
SRC_DIR			:=	./src
INC_DIR			:=	./include
BUILD_DIR		:=	./build
OBJS			:=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
LIB				:=	../libft/libft.a

################################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run "make ft_printf_test" to test the lilbftprintf.a"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings#################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = libftprintf_debug.a
LIB = ../libft/libft_debug.a
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
	$(MAKE) -C ../libft/

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ../libft/
	@echo "Objects libft cleaned"

fclean: clean
	$(RM) $(NAME) printf_gdb
	$(MAKE) fclean -C ../libft/
	@echo "Library printf cleaned"

re: fclean all

ft_printf_tester: all
	cd test/ft_printf_tester; sh test m

main:
	gcc src/main.c -L. -lftprintf_debug -g -o printf_gdb

.PHONY: all clean fclean re fr_printf_tester
