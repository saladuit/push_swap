# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    unit_makefile.mk                                |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/06/23 16:20:51 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/07/11 14:12:47 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #


UNIT_TEST			=push_swap_unit_test
UNIT_SRCS			=push_swap_tester.c redirect_all_std.c \
					 argv_checker_test.c init_integer_array_tester.c \
					 array_check_test.c parse_argv_to_array_test.c  \
					 push_swap_test.c init_stack_test.c \
					 make_positive_test.c

UNIT_OBJS			=$(addprefix ../$(BUILD_DIR)/, $(UNIT_SRCS:%.c=%.o))
PRODUCTION_OBJS		=$(addprefix ../, $(OBJS))

UNIT_LIBS			=$(addprefix ../, $(LIBFT))

UNIT_HEADERS		:=$(INCLUDE_DIR)/unit_push_swap.h \
					  ../$(LIBFT_INCLUDE_DIR)/libft.h \
					  ../$(INCLUDE_DIR)/push_swap.h

UNIT_INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(UNIT_HEADERS))))
