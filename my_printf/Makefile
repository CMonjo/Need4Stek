##
## EPITECH PROJECT, 2017
## libmy compilator
## File description:
## compiles a libmy.a
##

SRC	=	my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_printf.c		\
		my_putnbr_basex.c	\
		my_putnbr_base.c	\
		my_putnbr_baseun.c	\
		my_putnbr_basep.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

BIN	=	a.out

FINAL	=	$(NAME)

all:	AH

AH:
	gcc -c $(SRC) -W -Wall -Wextra -I.
	ar rc $(NAME) *.o
clean:
	rm -f *.o

fclean:	clean
	rm -f $(FINAL)

re:	fclean all