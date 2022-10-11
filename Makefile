FLAG = -Wall -Wextra -Werror -lmlx -lXext -lX11 -lm

NAME = fdf

INC = -I ./include

SRC =	./src/main.c \
		./src/start_matriz.c \
		./src/exit.c \
		./src/start_mlx.c \
		./src/mlx_utils.c \
		./src/hooks.c \
		

LIBFTPATH = ./lib

LIBFT = ./lib/libft.a

CC = cc

all: $(NAME)

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	$(CC) $(SRC) $(LIBFT) $(FLAG) $(INC) -o $(NAME)

clean:
	make fclean -C ${LIBFTPATH}

rmv:
	rm -f $(NAME)

fclean: clean
	rm fdf

re: fclean all

refast: rmv all
.PHONY: all clean fclean re