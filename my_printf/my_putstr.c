/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** name
*/

#include <my.h>

int	my_putstr(va_list va)
{
	char const *str = va_arg(va, char*);
	int i = 0;
	int res = 0;

	while (str[i] != '\0') {
		res += my_putchar2(str[i]);
		i += 1;
	}
	return (res);
}

int	my_putstrs(va_list va)
{
	char const *str = va_arg(va, char*);
	int i = 0;
	int res = 0;

	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] == 127) {
			my_putchar2('\\');
			res += my_putnbr_base(str[i], "01234567\0");
			i += 1;
		} else
			res += my_putchar2(str[i]);
		i += 1;
	}
	return (res);
}
