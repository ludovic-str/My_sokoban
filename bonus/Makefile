##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make
##

SRC =	src/main.c		\
		src/utils.c		\
		src/error.c		\
		src/moveplayer.c	\
		src/goodo.c			\
		src/map.c			\
		src/goodx.c		\
		src/blocked.c	\
		src/colorprint.c	\
		src/colorswitch.c	\
		src/menu.c			\
		src/menuprint.c		\
		src/title.c			\
		src/winloose.c		\
		src/freealot.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS += -g

all:  $(NAME)

$(NAME):	$(OBJ)
	make -C ./src/lib
	gcc $(OBJ) -o $(NAME) $(CFLAGS) -Lsrc/lib -lmy -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./src/lib

re: fclean all