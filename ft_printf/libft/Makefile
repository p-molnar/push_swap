# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pmolnar <pmolnar@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/04 17:46:44 by pmolnar       #+#    #+#                  #
#    Updated: 2022/06/01 16:11:29 by pmolnar       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
YELLOW		=	\033[1;33m
DEF			=	\033[0m

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

UTIL_SRC	=	ft_isupper.c		ft_islower.c		\
				ft_isspace.c		ft_count.c			\
				ft_dtoa.c			ft_abs.c			\
				ft_isnegative.c		ft_get_num_len.c	\
				ft_reverse_str.c	ft_atod.c			\
				ft_atof.c			ft_min_i.c			\
				ft_max_i.c			ft_min_f.c			\
				ft_max_f.c			

PART1_SRC	= 	ft_isalpha.c		ft_isdigit.c		\
				ft_isalnum.c		ft_isascii.c		\
				ft_isprint.c		ft_strlen.c			\
				ft_memset.c			ft_bzero.c			\
				ft_memcpy.c			ft_memmove.c		\
				ft_strlcpy.c		ft_strlcat.c		\
				ft_toupper.c		ft_tolower.c		\
				ft_strchr.c			ft_strrchr.c		\
				ft_strncmp.c		ft_memchr.c			\
				ft_memcmp.c			ft_strnstr.c		\
				ft_atoi.c			ft_calloc.c			\
				ft_strdup.c			
	
PART2_SRC =		ft_substr.c			ft_strjoin.c		\
				ft_strtrim.c		ft_split.c			\
				ft_itoa.c			ft_strmapi.c		\
				ft_striteri.c		ft_putchar_fd.c		\
				ft_putstr_fd.c		ft_putendl_fd.c		\
				ft_putnbr_fd.c		

BONUS_SRC	=	ft_lstnew_bonus.c			ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c			ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c		ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c			ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c

SRC 		=	$(addprefix libc/, $(PART1_SRC)) \
				$(addprefix libc/, $(PART2_SRC))	\
				$(addprefix additional/, $(UTIL_SRC))

OBJ 		= 	$(SRC:.c=.o)

B_OBJ 		= 	$(addprefix linked_list/, $(BONUS_SRC:.c=.o))

NAME 		= 	libft.a

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) successfully compiled\n$(DEF)"
%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c $^ -o $@

bonus:
	@make OBJ="$(B_OBJ)" all

clean:
	rm -f $(OBJ) $(B_OBJ)
	@echo "$(GREEN)Object files are deleted\n$(DEF)"

fclean: clean
	rm -f $(NAME)
	@echo "$(GREEN)$(NAME) is deleted\n$(DEF)"

re: fclean all

.PHONY: all clean fclean re bonus
