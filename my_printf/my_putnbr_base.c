/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** name
*/

#include <my.h>

int	ft_strlen(char const *str)
{
	int i = 0;
	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}

int	calcul(int nbr, int lenght, char const *base)
{
	int i = nbr / lenght;
	int j = nbr % lenght;
	int res = 0;

	if (nbr < 0) {
		my_putchar2('-');
		res += 1;
		res += calcul(-nbr, lenght, base);
	} else if (i >= lenght)
		calcul(i, lenght, base);
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

int	my_putnbr_base(int nbr, char const *base)
{
	int lenght = ft_strlen(base);

	return (calcul(nbr, lenght, base));
}
