/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** name
*/

#include <stdarg.h>
#include <my.h>

int	ok(int nb)
{
	int res = 0;

	if (nb > 9) {
		res += ok(nb / 10);
		res += my_putchar2((nb % 10) + 48);
      	} else
		res += my_putchar2(nb + 48);
	return (res);
}

int	my_put_nbr2(int nb)
{
	int res = 0;

	if (nb == -2147483648) {
		res += my_putchar2('-');
		res += my_putchar2('2');
		res += my_put_nbr2(147483648);
	} else if (nb < 0) {
		res += my_putchar2('-');
		res += my_put_nbr2(-nb);
	} else {
		res += ok(nb);
	}
	return (res);
}

int	my_put_nbr(va_list va)
{
	int nb = va_arg(va, int);

	return (my_put_nbr2(nb));
}
