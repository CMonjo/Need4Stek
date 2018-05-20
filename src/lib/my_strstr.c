/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** Find a string within another.
*/

#include "leolib.h"

char *my_strstr(char const *str, char *to_find)
{
	int i = 0;
	int j = 0;
	int length = len(to_find);

	if (!str[0])
		return (to_find[0] ? NULL : (char*)&str[0]);
	if (length == 0)
		return ((char*)(&str[0]));
	while (str[i] != '\0') {
		if (str[i] == to_find[j]) {
			j++;
		} else {
			if (j > 0 && j == length)
				break;
			}
		i += 1;
	}
	if (j != length)
		return (NULL);
	return ((char*)(&str[i - j]));
}
