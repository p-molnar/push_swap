# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pmolnar <pmolnar@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/25 17:30:10 by pmolnar       #+#    #+#                  #
#    Updated: 2022/06/02 16:08:04 by pmolnar       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libftprintf.a 
SRC  		:=	ft_printf.c							\
				src/print_formatted_arg.c			\
				src/formatting.c					\
				src/parse.c							\
				src/parse.c							\
				src/populate_struct.c				\
				src/put.c							\
				utils/ft_printf_formatting_utils.c	\
				utils/ft_printf_utils.c	

HEADER_DIR	?=	headers

LIBFT_DIR 	?=	libft
LIBFT		?=	libft.a

CC 			=	gcc
CFLAGS 		?=	-Wall -Wextra -Werror -I $(HEADER_DIR)

OBJ = $(SRC:.c=.o)

RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
DEF		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	make $(LIBFT) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) was sucessfully made\n$(DEF)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	make fclean	--directory=libft
	rm -f $(OBJ)
	@echo "$(GREEN)Object files successfully deleted\n$(DEF)"

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)Executable file(s) sucessfully deleted\n$(DEF)"

re: fclean all

norm:
	norminette $(SRC) $(HEADER_DIR)

.PHONY: all bonus clean fclean re norm
