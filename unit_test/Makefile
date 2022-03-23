# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/03/21 10:11:56 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/03/23 20:55:16 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include	../makerc/utils.mk
include ../makerc/colours.mk
include	../makerc/srcs.mk
include	src/usrcs.mk

PROJECT		=	Unit-Test
NAME		:=	$(if $(or $(DEBUG), $(FSAN)),pushtest_debug,pushtest)

CC			=	gcc
RM			=	rm -rfv
CFLAGS		=	-Wall -Wextra -Werror -coverage $(if $(DEBUG),-g) \
				$(if $(FSAN),-fsanitize=address -g)
CRITERION	=	-lcriterion

OBJS		=	$(addprefix $(BUILD_DIR)/, $(SRCS:%.c= %.o))
OBJS		+=	$(addprefix $(BUILD_DIR)/, $(USRCS:%.c= %.o))
SRC_DIR		=	./src
PSRC_DIR	=	../src
BUILD_DIR	=	./build

LIB_DIR		:=	../libs/libft
LIBFT		:=	$(if $(or $(FSAN), $(DEBUG)),$(LIB_DIR)/libft_debug.a,$(LIB_DIR)/libft.a)
HEADERS			=	$(LIB_DIR)/include/libft.h \
					../include/push_swap.h \

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
	$(CC) $(CFLAGS) $(CRITERION) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@$(call print_prefix,"$(PROJECT)","make")
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"
	@echo $(MAKE_DATA) > $(MAKE_TXT)
	./$(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)
	@printf "$(CLEAR_REST_OF_LINE)\r"

$(BUILD_DIR)/%.o: $(PSRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call print_prefix,"$(PROJECT)","make")
	@$(call exec_no_nl,$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@)
	@printf "$(CLEAR_REST_OF_LINE)\r"

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	@$(call print_prefix,"$(PROJECT)","$@")
	$(RM) $(NAME) pushtest_debug *.dSYM $(MAKE_TXT)
	@$(MAKE) fclean -C $(LIB_DIR)

debug:
	@$(MAKE) DEBUG=1

fsan:
	@$(MAKE) FSAN=1

re: fclean all

.PHONY: all clean fclean re debug fsan
################################################################################
