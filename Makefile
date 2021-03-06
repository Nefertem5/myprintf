NAME	=	libftprintf.a
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g
SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.

clean:
	make -C libft clean
	rm -f *.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	
re: fclean all
