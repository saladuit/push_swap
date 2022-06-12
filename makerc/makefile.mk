
SRCS			=push_swap.c
MAIN 			:=main.c

SRC_DIR			:=src
BUILD_DIR		:=build
UNIT_DIR		:=unit_test

OBJS			=$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
MAIN_OBJ		=$(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

HEADERS			=	$(LIB_DIR)/include/libft.h \
					include/push_swap.h
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

LIB_DIR			=	libs/libft
LIBFT			:=  $(LIB_DIR)/libft.a
COVERAGE		=$(SRCS:.c=.gcda)	\
	$(SRCS:.c=.gcno) \
	$(UNIT_SRCS:.c=.gcno) \
	$(UNIT_SRCS:.c=.gcda)
