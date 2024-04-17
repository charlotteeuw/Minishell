##
## EPITECH PROJECT, 2024
## $MAKEFILE
## File description:
## Makefile for minishell2
##

NAME	=	mysh

SRC		=	$(shell find . -type f -name '*.c')

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= 	-I./include/ -g -W

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *.log
	rm -f *.gcda
	rm -rf *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
