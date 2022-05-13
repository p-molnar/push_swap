CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
NAME		=	push_swap
HEADER_FILES=	include

SRC			=	main.c 					\
				parse.c					\
				error.c					\
				list_operations.c		\
				stack_operations.c		\
				stack_operations_util.c	\
				check_sorting.c			\
				sorting_algo.c			\
				sorting_algo_util.c		\
				list_indexing.c			\
				stack_preparation.c		\
				stack_preparation_util.c\
				free_nodes.c			\

OBJ			=	$(addprefix obj/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o:	src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(NAME) obj

re: fclean
	make all

norm:
	norminette src/$(SRC)

.PHONY: all clean fclean re