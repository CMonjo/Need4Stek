/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** name
*/

#include <my.h>

int	my_putchar2(char c)
{
        write(1, &c, 1);
	return (1);
}

int	my_putchar(va_list va)
{
	char c = va_arg(va, int);

	my_putchar2(c);
	return (1);
}
