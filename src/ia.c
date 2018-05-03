/*
** EPITECH PROJECT, 2017
** n4s_package
** File description:
** ia.c
*/

#include "main.h"

int main(void)
{
	char *buf;
	char **args;
	size_t buff_size = 0;

	my_printf("START_SIMULATION\n");
	getline(&buf, &buff_size, stdin);
	fprintf(stderr, "%s\n", buf);
	while(1) {
		my_printf("CAR_FORWARD:%d\n", 1);
		getline(&buf, &buff_size, stdin);
		fprintf(stderr, "%s\n", buf);
		args = my_str_to_word_array(buf, ':');
		for (int i = 0; args[i]; i++) {
			my_printf("\n");
			getline(&buf, &buff_size, stdin);
			fprintf(stderr, "%s\n", buf);
			if (!strcmp(args[i], "Track Cleared")) {
				my_printf("CAR_FORWARD:%d\n", 0);
				getline(&buf, &buff_size, stdin);
				fprintf(stderr, "%s\n", buf);
				goto azerty;
			}
		 }
	}
	azerty:
	sleep(5);
	my_printf("STOP_SIMULATION\n");
    //     printf("");
    //     printf("%s\n", buf);
    // }
}
