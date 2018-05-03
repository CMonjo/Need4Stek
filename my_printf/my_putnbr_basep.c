/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** name
*/

#include <my.h>

int	ft_strlen(char const *str);

int	calculp(long long nbr, long long lenght, char const *base)
{
	long long i = nbr / lenght;
	long long j = nbr % lenght;
	int res = 0;

	if (nbr < 0) {
		my_putchar2('-');
		res += calculp(-nbr, lenght, base);
	} else if (i >= lenght)
		calculp(i, lenght, base);
	else {
		switch (i)
		{
		case 0:
			break;
		default :
			my_putchar2(base[i]);
			res += 1;
		}
	}
	my_putchar2(base[j]);
	return (res + 1);
}

int	my_putnbr_basep(va_list va)
{
	char *base = "0123456789abcdef";
	long long lenght = ft_strlen(base);

	return (calculp(va_arg(va, long long), lenght, base));
}
