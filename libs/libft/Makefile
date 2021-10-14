# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                        |o_o || |                 #
#                                                      +:+                     #
#    By: safoh <safoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/08/11 13:33:46 by safoh         #+#    #+#                  #
#    Updated: 2021/10/14 16:28:53 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a
CC				:=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				:=	rm -f

################################################################################
# SRCS			=	RESOURCES
# SRC_DIR		=	SOURCES DIRECTORY
# INC_DIR		=	INCLUDES DIRECTORY
# BUILD_DIR		=	BUILD DIRECTORY
# OBJS			=	OBJECTS

SRCS			=	ft_memset.c ft_bzero.c ft_memcpy.c ft_strlen.c ft_atoi.c \
		ft_memmove.c ft_memccpy.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_strchr.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_putnbr_fd.c ft_calloc.c ft_memchr.c ft_strmapi.c ft_itoa.c \
		ft_numlen.c ft_uitoa.c ft_putuint_fd.c ft_uitoh.c ft_strtoupper.c \
		ft_strtolower.c ft_ultoh.c ft_sgdnumlen.c ft_strnew.c ft_memalloc.c \
		ft_lstadd_front.c ft_lstnew.c ft_memdel.c ft_strdel.c ft_lstsize.c
SRC_DIR 		:=	./src
INC_DIR 		:=	./include
BUILD_DIR		:=	./build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

###############################################################################
# MESSSAGE		=	Message after compiling
# C_MESSAGE		=	Message for building objects

MESSSAGE		=	"Run ./tests/Libftest/grademe.sh to test the libft library"
C_MESSAGE		=	"Building C objects... %-33.33s\r"

#################################Debug_settings################################
ifdef DEBUG
CFLAGS	+=	-g
NAME = libft_debug.a
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

$(NAME): $(OBJS)
	@echo "\n"
	ar rc $@ $^
	@echo $(MESSSAGE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf $(C_MESSAGE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "Objects libft cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Library libft cleaned"

re: fclean all

libft_tester: re
	bash tests/libft-war-machine/grademe.sh -d -u $(FILE)

libft_unit_test: re
	$(MAKE) -C ./tests/libft-unit-test f $(FILE)

main: all
	$(CC) $(CFLAGS) src/main.c -lft_debug -o libft_gdb
	./libft_gdb

.PHONY: all clean fclean re libft_tester main
