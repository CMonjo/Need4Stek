/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_putchar(va_list va);

int	my_putstrs(va_list va);

int	my_putnbr_baseb(va_list va);

int	my_putnbr_baseun(unsigned int nbr, char const *base);

int	my_putnbr_basex(va_list va);

int	my_putnbr_basep(va_list va);

int	my_putnbr_baseX(va_list va);

int	my_putnbr_baseu(va_list va);

int	my_putnbr_baseo(va_list va);

int	my_putnbr_base(int nbr, char const *base);

int	my_putchar2(char c);

int	my_put_nbr(va_list va);

int	my_putstr(va_list va);

int	my_strlen(char const *str);

int	sum_stdarg(int i, int nb, ...);

int	my_printf(char *s, ...);

#endif /* MY_H_ */

typedef struct	tab {
	char balise;
	int (*fptr)(va_list);
}		tab_t;
