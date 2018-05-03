/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** name
*/

#include <my.h>

int	ft_strlen(char const *str);

int	calculun(unsigned int nbr, int lenght, char const *base)
{
	int i = nbr / lenght;
	int j = nbr % lenght;
	int res = 0;

        if (i >= lenght)
		res += calculun(i, lenght, base);
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

int	my_putnbr_baseun(unsigned int nbr, char const *base)
{
	int lenght = ft_strlen(base);

	return (calculun(nbr, lenght, base));
}
