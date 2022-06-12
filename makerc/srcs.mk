SRCS		=push_swap.c
SRC_DIR		:=./src
BUILD_DIR	:=./build
OBJS		=$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
