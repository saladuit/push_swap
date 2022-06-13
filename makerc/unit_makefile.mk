# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    unit_makefile.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safoh <safoh@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:18:58 by safoh             #+#    #+#              #
#    Updated: 2022/06/13 17:39:44 by safoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNIT_TEST			=push_swap_unit_test
UNIT_SRCS			=push_swap_tester.c redirect_all_std.c argc_checker_test.c \
					 argv_checker_test.c

UNIT_OBJS			=$(addprefix ../$(BUILD_DIR)/, $(UNIT_SRCS:%.c=%.o))
PRODUCTION_OBJS		=$(addprefix ../, $(OBJS))

UNIT_LIBS			=$(addprefix ../, $(LIBFT))

UNIT_HEADERS		:=$(INCLUDE_DIR)/unit_push_swap.h \
					  ../$(LIBFT_INCLUDE_DIR)/libft.h \
					  ../$(INCLUDE_DIR)/push_swap.h

UNIT_INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(UNIT_HEADERS))))
