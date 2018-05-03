/*
** EPITECH PROJECT, 2018
** Project getnextline
** File description:
** GetNextLine
*/

#include "leolib.h"

int end(char *str)
{
	int i = -1;

	while (str && str[++i]) {
		if (str[i] == 10)
			return (i);
	}
	return (-1);
}

int dis(char *str)
{
	int i = -1;

	while (str && str[++i]);
	return (i == -1 ? 0 : i);
}

char *read_next(int fd, int n)
{
	char *buffer = malloc(sizeof(char) * (n + 1));
	int bytes = read(fd, buffer, n);

	if (!buffer)
		return (NULL);
	if (bytes < 1) {
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (bytes == 0 ? NULL : buffer);
}

char *cat(char *str1, char *str2, int end, int op)
{
	int len_a = str1 ? dis(str1) : 0;
	char *ns = malloc(sizeof(char) * (len_a + end + 1));
	int i = 0;
	int j = 0;

	if (!ns)
		return (NULL);
	while (str1 && str1[i]) {
		ns[i] = str1[i];
		i += 1;
	}
	while (str2[j] && j < end) {
		ns[i + j] = str2[j];
		j += 1;
	}
	ns[i + j] = 0;
	if (str1)
		free(op == -3 ? str1 : str1 - op);
	return (ns);
}

char *get_next_line(int fd)
{
	char *bff;
	char *s = NULL;
	static char *last = NULL;

	int search = end(last) != -1 ? 1 : 0;
	if (last) {
		s = cat(s, last, end(last) == -1 ? dis(last) : end(last), -3);
		last = (end(last) == -1) ? NULL : last;
		last += (end(last) != -1) ? end(last) + 1 : 0;
	}
	while (search == 0 && (bff = read_next(fd, READ_SIZE))) {
		s = cat(s, bff, end(bff) < 0 ? READ_SIZE : end(bff), -3);
		if (end(bff) != -1)
			break;
		free(bff);
	}
	if (!last && bff)
		last = cat(bff + end(bff) + 1, "", 0, end(bff) + 1);
	return (s);
}