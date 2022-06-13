# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 21:19:17 by safoh             #+#    #+#              #
#    Updated: 2022/06/13 21:19:59 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=push_swap.c
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
