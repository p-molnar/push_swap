CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
HEADER_FILES=	include

FT_PRINTF_LIB	=	ft_printf/
FT_PRINTF		= 	libftprintf.a

GNL			=	get_next_line.c			\
				get_next_line_utils.c

PS_NAME		=	push_swap
CHECKER_NAME=	checker

PS_SRC		=	main.c 					\
				input.c					\
				error.c					\
				list_functions.c		\
				stack_operations.c		\
				stack_operation_util.c	\
				check_sorting.c			\
				sorting_algo.c			\
				sorting_algo_util.c		\
				list_indexing.c			\
				stack_preparation.c		\
				stack_preparation_util.c\
				free_nodes.c			\

CHECKER_SRC	=	checker.c				\
				push_ops.c				\
				rev_rotate_ops.c		\
				rotate_ops.c			\
				swap_ops.c				\

PS_OBJ_CHECKER	=	check_sorting.c		\
					error.c				\
					free_nodes.c		\
					input.c				\
					stack_operations.c	\
					stack_operation_util.c \
					list_functions.c		\

PS_OBJ			=	$(addprefix obj/, $(PS_SRC:.c=.o))
CHECKER_OBJ		=	$(addprefix obj/, $(CHECKER_SRC:.c=.o))		\
					$(addprefix obj/, $(PS_OBJ_CHECKER:.c=.o))	\
					$(addprefix obj/, $(GNL:.c=.o))

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
DEF		=	\033[0m

all:	$(PS_NAME) $(CHECKER_NAME)


$(PS_NAME): $(FT_PRINTF_LIB)$(FT_PRINTF) $(PS_OBJ)
	$(CC) $(CFLAGS) $(PS_OBJ) $(FT_PRINTF_LIB)$(FT_PRINTF) -o $(PS_NAME)
	@echo "$(GREEN)$(PS_NAME) was sucessfully made\n$(DEF)"

obj/%.o:	src/push_swap/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

$(FT_PRINTF_LIB)$(FT_PRINTF):
	make $(FT_PRINTF) --directory=$(FT_PRINTF_LIB)

bonus: $(CHECKER_NAME)

$(CHECKER_NAME):	$(CHECKER_OBJ) $(FT_PRINTF_LIB)$(FT_PRINTF) $(GNL_OBJ) $(PS_OBJ)	
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(FT_PRINTF_LIB)$(FT_PRINTF) $(GNL_OBJ) -o $(CHECKER_NAME)
	@echo "$(GREEN)$(CHECKER_NAME) was sucessfully made\n$(DEF)"

obj/%.o:	*/*/%.c
	mkdir -p obj
	$(CC) -D BUFFER_SIZE=100 $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

clean:
	rm -rf obj
	make clean --directory=$(FT_PRINTF_LIB)

fclean:	clean
	rm -rf $(PS_NAME) obj
	rm -f $(FT_PRINTF)
	rm -f $(CHECKER_NAME)
	make fclean --directory=$(FT_PRINTF_LIB)

re: fclean
	make all

norm:
	norminette include
	norminette src

.PHONY: all clean fclean re bonus norm