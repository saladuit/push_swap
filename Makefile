# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 11:07:01 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/21 18:14:22 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include makerc/colours.mk
include makerc/utils.mk
include makerc/srcs.mk

################################################################################
PROJECT		= Push-Swap
NAME		=	$(if $(or $(DEBUG), $(FSAN)), push_swap_debug, push_swap)

CC			:=	gcc
RM			:=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror $(if $(DEBUG), -g) \
				$(if $(FSAN), -fsanitize=address -g)

SRC_DIR		=	./src
BUILD_DIR	=	./build
OBJS		=	$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))

LIB_DIR		=	libs/libft
LIBFT		:= $(if $(or $(FSAN), $(DEBUG)), $(LIB_DIR)/libft_debug.a, $(LIB_DIR)/libft.a)
HEADERS			=	$(LIB_DIR)/include/libft.h \
					include/push_swap.h
INCLUDE_FLAGS	+= $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS += $(addprefix -L, $(sort $(dir $(USER_LIBS))))

MAKE_TXT		:=	$(addprefix $(BUILD_DIR)/, .make_data.txt)
MAKE_DATA		:=	$(CFLAGS) $(LIB_FLAGS) $(INCLUDE_FLAGS) $(sort $(OBJECTS))
ifneq	($(shell echo $(MAKE_DATA)), $(shell cat "$(MAKE_TXT)" 2> /dev/null))
PRE_RULES		:=	fclean
endif

ifndef PROJECT_SPACING
	export PROJECT_SPACING := 11
endif
################################################################################
all: $(PRE_RULES) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(call print_prefix,"$(PROJECT)","make")
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@$(call print_prefix,"$(PROJECT)","make")
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"
	@echo $(MAKE_DATA) > $(MAKE_TXT)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)
	@printf "$(CLEAR_REST_OF_LINE)\r"

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

################################################################################
clean:
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(NAME) push_swap_debug *.dSYM $(MAKE_TXT)
	@$(MAKE) fclean -C $(LIB_DIR)

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

re: fclean all

push_swap_tester: all
	bash push_swap_tester/basic_test.sh

.PHONY: all clean fclean push_swap_tester re debug fsan
################################################################################
