/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	while (i < n) {
		if (dest[i] == '\0')
			break;
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}