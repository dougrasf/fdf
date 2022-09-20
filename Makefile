FLAG = -Wall -Wextra -Werror -lmlx -lXext -lX11

NAME = fdf

SRC =	main.c \
		

LIBFTPATH = ./lib

LIBFT = ./lib/libft.a

CC = cc

all: $(NAME)

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	$(CC) $(SRC) $(LIBFT) $(FLAG) -o $(NAME)

clean:
	make fclean -C ${LIBFTPATH}

fclean: clean
	rm fdf

re: fclean all

.PHONY: all clean fclean re