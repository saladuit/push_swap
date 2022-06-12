UNIT_TEST			:=Push_Swap_Unit_Test
UNIT_DIR			:=./unit_test
UNIT_SRCS_DIR		:=$(UNIT_DIR)/src
UNIT_SRCS			=push_swap_tester.c redirect_all_std.c check_argc_test.c

UNIT_HEADERS		:=unit_test/include/unit_push_swap.h
UNIT_LFLAGS			:=-lcriterion
UNIT_OBJS			=$(UNIT_SRCS:.c=.o)
UNIT_INCLUDE_FLAGS	:=$(addprefix -I, $(sort $(dir $(UNIT_HEADERS))))

COVERAGE_DIR		:=./coverage
COVERAGE			=$(SRCS:.c=.gcda)			\
						$(SRCS:.c=.gcno)		\
						$(UNIT_SRCS:.c=.gcno)	\
						$(UNIT_SRCS:.c=.gcda)
