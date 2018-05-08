/*
** EPITECH PROJECT, 2017
** nfs_package
** File description:
** ia.c
*/

#include "main.h"

// {2000, "1\n"},
// {1500, "0.8\n"},
// {1000, "0.5\n"},
// {600, "0.4\n"},
// {400, "0.2\n"},
// {200, "0.1\n"},
// {0, "0.3\n"},

// {1500, "1\n"},
// {1250, "0.8\n"},
// {1000, "0.5\n"},
// {600, "0.4\n"},
// {400, "0.2\n"},
// {200, "0.1\n"},
// {0, "0.3\n"},

speed_t speed[] = {
	{2000, "1\n", 2},
	{1500, "0.8\n", 4},
	{1000, "0.5\n", 4},
	{600, "0.4\n", 4},
	{400, "0.2\n", 4},
	{200, "0.1\n", 4},
	{0, "0.3\n", 4},
};

direction_t direction[] = {
	{1500, "0.005\n", 6},
	{1000, "0.05\n", 5},
	{600, "0.1\n", 4},
	{400, "0.2\n", 4},
	{200, "0.3\n", 4},
	{0, "0.5\n", 4},
};

nfs_t *init_nfs(void)
{
	nfs_t *nfs = malloc(sizeof(nfs_t));

	nfs->mid = 0;
	nfs->speed = 0;
	nfs->alpha = 0;
	return(nfs);
}

int game_end(nfs_t *nfs)
{
	char *buf;
	size_t buf_size = 0;

	for (int i = 0; nfs->args[i] != NULL; i++) {
		if (!strcmp(nfs->args[i], "Track Cleared")) {
			write(1, "CAR_FORWARD:0\n", 14);
			getline(&buf, &buf_size, stdin);
			write(1, "STOP_SIMULATION\n", 16);
			exit(0);
		}
	}
	return (0);
}

void get_lidar(nfs_t *nfs)
{
	char *buf;
	size_t buf_size = 0;
	char **rays;

	write(1, "GET_INFO_LIDAR\n", 15);
	getline(&buf, &buf_size, stdin);
	fprintf(stderr, "lidar %s\n", buf);
	nfs->args = my_str_to_word_array(buf, ':');
	rays = my_str_to_word_array(buf, ':');
	for (int i = 0; i != 32 ; i++)
		nfs->rays[i] = atof(rays[i + 3]);
	nfs->mid = nfs->rays[14];
	game_end(nfs);
}

void set_speed(nfs_t *nfs)
{
	char *buf;
	size_t buf_size = 0;

	if (nfs->mid <= 199)
		write(1, "CAR_BACKWARDS:", 14);
	else
		write(1, "CAR_FORWARD:", 12);
	for (int i = 0; i != 7; i++) {
		if (nfs->mid >= speed[i].mid_s) {
			write(1, speed[i].set_speed, speed[i].len);
			break;
		}
	}
	getline(&buf, &buf_size, stdin);
	nfs->args = my_str_to_word_array(buf, ':');
	game_end(nfs);
}

void set_alpha(nfs_t *nfs)
{
	float dir = nfs->rays[0] - nfs->rays[31];
	char *buf;
	size_t buf_size = 0;

	write(1, "WHEELS_DIR:", 11);
	if (dir < 0)
		write(1, "-", 1);
	for (int i = 0; i != 6; i++) {
		if (nfs->mid >= direction[i].mid_s) {
			write(1, direction[i].set_direction, direction[i].len);
			break;
		}
	}
	getline(&buf, &buf_size, stdin);
	nfs->args = my_str_to_word_array(buf, ':');
	game_end(nfs);
}

int main(void)
{
	char *buf;
	size_t buf_size = 0;
	nfs_t *nfs = init_nfs();

	write(1, "START_SIMULATION\n", 17);
	getline(&buf, &buf_size, stdin);
	while(1) {
		get_lidar(nfs);
		set_alpha(nfs);
		get_lidar(nfs);
		set_speed(nfs);
	}
	return (0);
}
