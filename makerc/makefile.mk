# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    makefile.mk                                     |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/07/08 18:13:12 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/07/11 14:35:57 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

SRCS			=push_swap.c init.c argv_checker.c sort_radix.c swap.c \
				 sort_two.c sort_five.c sort_three.c
MAIN 			=main.c

SRC_DIR			:=src
INCLUDE_DIR		:=include
BUILD_DIR		:=build
UNIT_DIR		:=unit_test
LIB_DIR			:=libs
LIBFT_DIR		:=$(LIB_DIR)/libft
UNIT_INCLUDE_DIR	:=$(UNIT_DIR)/$(INCLUDE_DIR)
LIBFT_INCLUDE_DIR	:=$(LIBFT_DIR)/$(INCLUDE_DIR)


OBJS			=$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
MAIN_OBJ		=$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

HEADERS			=$(LIBFT_INCLUDE_DIR)/libft.h $(INCLUDE_DIR)/push_swap.h
INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(HEADERS))))

LIBFT			:=$(LIBFT_DIR)/libft.a

COVERAGE		=$(SRCS:.c=.gcda) $(SRCS:.c=.gcno) $(UNIT_SRCS:.c=.gcno) \
	$(UNIT_SRCS:.c=.gcda)
