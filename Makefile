CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
HEADER_FILES=	include

FT_PRINTF	=	ft_printf
FT_PRINTF_NAME = libftprintf.a

GNL			=	get_next_line_utils.c	\
				get_next_line.c

PS_NAME		=	push_swap
PS_SRC		=	main.c 					\
				parse.c					\
				error.c					\
				list_operations.c		\
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

CHECKER_NAME=	checker

PS_OBJ			=	$(addprefix obj/, $(PS_SRC:.c=.o))
CHECKER_OBJ		=	$(addprefix obj/, $(CHECKER_SRC:.c=.o))
GNL_OBJ			=	$(addprefix obj/, $(GNL:.c=.o))

all:	$(PS_NAME)

$(PS_NAME): $(FT_PRINTF_NAME) $(PS_OBJ)
	$(CC) $(CFLAGS) $(PS_OBJ) $(FT_PRINTF_NAME) -o $(PS_NAME)

obj/%.o:	sorter_src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

$(FT_PRINTF_NAME):
	make $(FT_PRINTF_NAME) --directory=$(FT_PRINTF)
	cp $(FT_PRINTF)/$(FT_PRINTF_NAME) .

bonus: $(CHECKER_NAME)

$(CHECKER_NAME):	$(CHECKER_OBJ) $(FT_PRINTF_NAME) $(GNL_OBJ) $(PS_OBJ)	
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(FT_PRINTF_NAME) $(GNL_OBJ) $(addprefix obj/, check_sorting.o error.o free_nodes.o parse.o stack_operations.o stack_operation_util.o list_operations.o) -o $(CHECKER_NAME)

obj/%.o:	*/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

clean:
	make clean --directory=$(FT_PRINTF)
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(PS_NAME) obj
	rm -f $(FT_PRINTF_NAME)
	rm -f $(CHECKER_NAME)
	make fclean --directory=$(FT_PRINTF)

re: fclean
	make re --directory=$(FT_PRINTF)
	make all

norm:
	norminette checker_src
	norminette sorter_src

.PHONY: all clean fclean re bonus 