/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** src/utils/my_strcpy.c : Copy an string into another.
*/

#include <stdlib.h>
#include <stdio.h>

int len(char const*);

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (len(src) + 1));
	if (!dest)
		return (NULL);
	dest = my_strcpy(dest, src);
	return (dest);
}