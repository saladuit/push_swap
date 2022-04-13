
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
CRITERION	=	-lcriterion

OBJS		=	$(addprefix $(BUILD_DIR)/, $(USRCS:%.c= %.o))
POBJS		=	$(addprefix $(PBUILD_DIR)/, $(SRCS:%.c= %.o))
SRC_DIR		=	./src
PSRC_DIR	=	../src
BUILD_DIR	=	./build
PBUILD_DIR	=	../build

LIB_DIR		:=	../libs/libft
LIBFT		:=	$(LIB_DIR)/libft.a
HEADERS		=	$(LIB_DIR)/include/libft.h \
			../include/push_swap.h \
			./include/

INCLUDE_FLAGS	+= $(addprefix -I, $(sort $(dir $(HEADERS))))
LIB_FLAGS += $(addprefix -L, $(sort $(dir $(USER_LIBS))))

$(NAME): $(OBJS) | $(PSWAP) $(LIBFT)
	$(CC) $(CFLAGS) $(CRITERION) $(POBJS) $(LIBFT) $^ $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CLEAR_REST_OF_LINE)\r"
