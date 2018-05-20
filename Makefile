##
## EPITECH PROJECT, 2017
## Project N4S
## File description:
## Build ai binary.
##

SRC	=	src/main.c	\
		src/n4s.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -W -Wall -I ./include/

LDFLAGS	=	-L ./src/lib/ -l leo

NAME	=	ai

CC	=	gcc

all: $(NAME)

$(NAME):	$(OBJ)
		make -C ./src/lib/
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

n4s:	all
	cp ai ./n4s/

clean:
	make clean -C ./src/lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./src/lib/
	rm -f $(NAME)

re: fclean all