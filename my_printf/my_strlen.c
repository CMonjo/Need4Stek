/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** name
*/

#include <my.h>

int	my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0')
		i += 1;
	return (i);
}
