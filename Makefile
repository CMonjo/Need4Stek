##
## EPITECH PROJECT, 2017
## Project N4S
## File description:
## Build ai binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/

LIB	=	-L ./src/lib/ -lleo

SRC	=	src/main.c	\

OBJ	=	$(SRC:.c=.o)

MAKE_LIBMY	=	make -C ./src/lib/

NAME	=	ai

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE_LIBMY)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

n4s:	all
	cp ai ./n4s/

clean:
	rm -f $(OBJ)
	$(MAKE_LIBMY) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_LIBMY) fclean

re: fclean all
