HEADERS			=	$(LIB_DIR)/include/libft.h \
					include/push_swap.h
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))
