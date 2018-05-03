/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** reproduce the printf C lib
*/

#include <my.h>

tab_t	tab[] = {
	{'c', my_putchar},
	{'s', my_putstr},
	{'i', my_put_nbr},
	{'x', my_putnbr_basex},
	{'o', my_putnbr_baseo},
	{'d', my_put_nbr},
	{'u', my_putnbr_baseu},
	{'X', my_putnbr_baseX},
	{'p', my_putnbr_basep},
	{'b', my_putnbr_baseb},
	{'S', my_putstrs},
	{0, 0}
};

void	pern(va_list va, int res)
{
	int *resu = va_arg(va, int*);

	*resu = res;
}

int	norme(char *balise, va_list va, int res)
{
	int i;
	int j;
	int stop = 0;

	for (j = 0; balise[j] && stop == 0; j += 1) {
		if (balise[j] == '%') {
			my_putchar2('%');
			return (1);
		} else if (balise[j] == 'n') {
			pern(va, res);
			return (0);
		}
		for(i = 0; tab[i].balise != 0; i += 1) {
			if (balise[j] == tab[i].balise)
				return ((tab[i].fptr)(va));
		}
	}
	return(0);
}

int	my_printf(char *s, ...)
{
	int i;
	va_list va;
	int res = 0;

	va_start (va, s);
	for (i = 0; s[i]; i += 1) {
		if (s[i] == '%') {
			i += 1;
			res += norme(&s[i], va, res);
	        } else {
			my_putchar2(s[i]);
			res += 1;
		}
	}
	va_end (va);
	return (res);
}
