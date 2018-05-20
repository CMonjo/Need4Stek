/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** Split a string into tokens by a user char.
*/

#include <stdlib.h>

char *my_strncpy(char*, char const*, int n);

int char_is_sep(char c, char sep)
{
	if (sep == c || !c)
		return (0);
	return (1);
}

int get_word_start(char const *str, int wanted_word, char sep)
{
	int x = 0;
	int word_length = 0;
	int word_count = 0;
	int res = 0;

	while (str[x]) {
		word_length = 0;
		while (char_is_sep(str[x + word_length], sep) == 1)
			word_length += 1;
		if (word_length != 0) {
			x = x + word_length;
			word_count += 1;
			(word_count == wanted_word) ? res = 1 : 0;
		} else
			x += 1;
		if (res == 1)
			return (x - word_length);
	}
	return (0);
}

int get_word_number(char const *str, char sep)
{
	int x = 0;
	int word_length = 0;
	int word_count = 0;

	while (str[x]) {
		word_length = 0;
		while (char_is_sep(str[x + word_length], sep) == 1) {
			word_length += 1;
		}
		if (word_length != 0) {
			x = x + word_length;
			word_count += 1;
		} else
			x += 1;
	}
	return (word_count);
}

int get_word_length(char const *str, int wanted_word, char sep)
{
	int x = 0;
	int wanted_length = 0;
	int word_length = 0;
	int word_count = 0;

	while (str[x]) {
		word_length = 0;
		while (char_is_sep(str[x + word_length], sep) == 1) {
			word_length += 1;
		}
		if (word_length != 0) {
			x = x + word_length;
			word_count += 1;
			(word_count == wanted_word) ?
			wanted_length = word_length : 0;
		} else
			x += 1;
	}
	return (wanted_length);
}

char **my_str_to_word_array(char const *str, char sep)
{
	int word_count = get_word_number(str, sep);
	char **response_array = malloc(sizeof(char*) * (word_count + 1));
	int word_length = 0;
	int word_start = 0;
	int a = -1;
	int b = 0;

	if (!response_array)
		return (NULL);
	while (++a < word_count) {
		b = -1;
		word_length = get_word_length(str, a + 1, sep);
		word_start = get_word_start(str, a + 1, sep);
		response_array[a] = malloc(sizeof(char) * (word_length + 1));
		while (++b < word_length)
			response_array[a][b] = str[word_start + b];
		response_array[a][word_length] = '\0';
	}
	response_array[word_count] = 0;
	return (response_array);
}
