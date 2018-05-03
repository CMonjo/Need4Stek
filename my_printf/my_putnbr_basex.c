/*
** EPITECH PROJECT, 2017
** my_putnbr_basex
** File description:
** choose which base is it
*/

#include <my.h>

int	my_putnbr_basex(va_list va)
{
	int nb = va_arg(va, int);
	unsigned int un = nb;

	return (my_putnbr_baseun(un, "0123456789abcdef\0"));

}

int	my_putnbr_baseX(va_list va)
{
	int nb = va_arg(va, int);
	unsigned int un = nb;

	return (my_putnbr_baseun(un, "0123456789ABCDEF\0"));

}

int	my_putnbr_baseo(va_list va)
{
	int nb = va_arg(va, int);
	unsigned int un = nb;

	return (my_putnbr_baseun(un, "01234567\0"));

}

int	my_putnbr_baseu(va_list va)
{
	int nb = va_arg(va, int);
	unsigned int un = nb;
	
	return (my_putnbr_baseun(un, "0123456789\0"));
}

int	my_putnbr_baseb(va_list va)
{
	int nb = va_arg(va, int);
	unsigned int un = nb;
	
	return (my_putnbr_baseun(un, "01\0"));
}
