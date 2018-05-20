/*
** EPITECH PROJECT, 2017
** CPE_n4s_2017
** File description:
** src/n4s.c
*/

#include "need_four_stek.h"

speed_t speed[] = {
	{2000, "1\n", 2},
	{1500, "0.8\n", 4},
	{1000, "0.65\n", 5},
	{1000, "0.5\n", 4},
	{600, "0.4\n", 4},
	{400, "0.2\n", 4},
	{100, "0.1\n", 4},
	{75, "0.3\n", 2},
};

direction_t direction[] = {
	{1500, "0.01\n", 5},
	{1000, "0.1\n", 4},
	{600, "0.15\n", 5},
	{400, "0.25\n", 5},
	{300, "0.40\n", 5},
	{200, "0.5\n", 4},
	{100, "0.75\n", 5},
};

nfs_t *init_nfs(void)
{
	nfs_t *nfs = malloc(sizeof(nfs_t));

	nfs->mid = 0;
	nfs->speed = 0;
	nfs->alpha = 0;
	for (int i = 0; i != 32; i++)
		nfs->rays[i] = 0;
	return (nfs);
}

int game_end(char *buffer)
{
	char *buf = NULL;
	size_t buf_size = 0;

	if (strstr(buffer, "Track Cleared")) {
		write(1, "CAR_FORWARD:0\n", 14);
		if (getline(&buf, &buf_size, stdin) == -1)
			exit(84);
		write(1, "STOP_SIMULATION\n", 16);
		exit(0);
	}
	if (strstr(buffer, "KO"))
		exit(84);
	return (0);
}

void get_lidar(nfs_t *nfs)
{
	char *buf = NULL;
	size_t buf_size = 0;
	char **rays;

	write(1, "GET_INFO_LIDAR\n", 15);
	if (getline(&buf, &buf_size, stdin) == -1)
		exit(84);
	rays = my_str_to_word_array(buf, ':');
	if (!rays[0] || !rays[1] || !rays[2])
		return;
	for (int i = 0; i != 32; i++) {
		if (!rays[i + 3])
			return;
		nfs->rays[i] = atof(rays[i + 3]);
	}
	nfs->mid = nfs->rays[15];
	game_end(buf);
}

void set_speed(nfs_t *nfs)
{
	char *buf = NULL;
	size_t buf_size = 0;

	if (nfs->mid <= 75)
		write(1, "CAR_BACKWARDS:", 14);
	else
		write(1, "CAR_FORWARD:", 12);
	for (int i = 0; i != 8; i++) {
		if (nfs->mid >= speed[i].mid_s) {
			write(1, speed[i].set_speed, speed[i].len);
			break;
		}
	}
	if (getline(&buf, &buf_size, stdin) == -1)
		exit(84);
	game_end(buf);
}

void set_alpha(nfs_t *nfs)
{
	float dir = nfs->rays[0] - nfs->rays[31];
	char *buf = NULL;
	size_t buf_size = 0;

	write(1, "WHEELS_DIR:", 11);
	if (dir < 0)
		write(1, "-", 1);
	for (int i = 0; i != 7; i++) {
		if (nfs->mid >= direction[i].mid_s) {
			write(1, direction[i].set_direction, direction[i].len);
			break;
		}
	}
	if (getline(&buf, &buf_size, stdin) == -1)
		exit(84);
	game_end(buf);
}