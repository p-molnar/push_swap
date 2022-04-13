CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address

NAME		=	push_swap

HEADER_FILES	=	include
LIBFT_DIR	=	libft
LIBFT		=	libft.a
LIBFT_PATH	=	$(LIBFT_DIR)/$(LIBFT)

SRC			=	main.c 					\
				parse.c					\
				error.c					\
				sl_list_ops.c			\
				check_sorting.c			\
				sorting_ops.c			\
				sorting_instructions.c	\
				algo.c					\

OBJ			=	$(addprefix obj/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME): $(LIBFT_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH) -o $(NAME)

obj/%.o:	src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -I $(HEADER_FILES) -c $^ -o $@

clean:
	rm -f $(OBJ)
	make clean --directory=$(LIBFT_DIR)

fclean:	clean
	rm -rf $(NAME) obj
	make fclean --directory=$(LIBFT_DIR)

re: fclean
	make all

$(LIBFT_PATH):
	make $(LIBFT) --directory=$(LIBFT_DIR)
	@sleep 1
	make bonus --directory=$(LIBFT_DIR)

.PHONY: all clean fclean re