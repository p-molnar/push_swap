NAME	=	push_swap
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra -fsanitize=address

SRC		= 	src/main.c 	\
OBJ		=	$(SRC:.c=.o)

$(NAME): all

all: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	mkdir -p obj
	$(CC) $(FLAGS) $(SRC) -c -o /obj

fclean:	clean
	rm -f $(NAME)

clean:
	rm -rf $(OBJ)

re: fclean
	all

.PHONY: all fclean clean re