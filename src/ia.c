/*
** EPITECH PROJECT, 2017
** nfs_package
** File description:
** ia.c
*/

#include "main.h"

speed_t speed[] = {
	{2000, "1"},
	{1500, "0.8"},
	{1000, "0.5"},
	{600, "0.4"},
	{400, "0.2"},
	{200, "0.1"},
	{0, "0.3"},
};

direction_t direction[] = {
	{1500, "0.005"},
	{1000, "0.05"},
	{600, "0.1"},
	{400, "0.2"},
	{200, "0.3"},
	{0, "0.5"},
};

nfs_t *init_nfs(void)
{
	nfs_t *nfs = malloc(sizeof(nfs_t));

	nfs->mid = 0;
	nfs->speed = 0;
	nfs->alpha = 0;
	return(nfs);
}

void get_lidar(nfs_t *nfs)
{
	char *buf;
	size_t buf_size = 0;
	int len_rays = 0;
	char **rays;

	my_printf("GET_INFO_LIDAR\n");
	getline(&buf, &buf_size, stdin);
	nfs->args = my_str_to_word_array(buf, ':');
	rays = my_str_to_word_array(buf, ':');
	for (; rays[len_rays] != NULL; len_rays++);
	for (int i = 0; len_rays == 36 && i != 32 ; i++)
		nfs->rays[i] = atof(rays[i + 3]);
	if (len_rays == 36)
		nfs->mid = nfs->rays[14];

}

int game_end(nfs_t *nfs)
{
	for (int i = 0; nfs->args[i] != NULL; i++) {
		if (!strcmp(nfs->args[i], "Track Cleared")) {
			my_printf("CAR_FORWARD:%d\n", 0);
			return (1);
		}
	}
	return (0);
}

void set_speed(nfs_t *nfs)
{
	char *buf;
	size_t buf_size = 0;

	if (nfs->mid <= 199)
		my_printf("CAR_BACKWARDS:");
	else
		my_printf("CAR_FORWARD:");
	for (int i = 0; i != 7; i++) {
		if (nfs->mid >= speed[i].mid_s) {
			my_printf("%s\n", speed[i].set_speed);
			break;
		}
	}
	getline(&buf, &buf_size, stdin);
	fprintf(stderr, "SPEED %s\n", buf);
}

void set_alpha(nfs_t *nfs)
{
	float dir = nfs->rays[0] - nfs->rays[31];
	char *buf;
	size_t buf_size = 0;

	my_printf("WHEELS_DIR:");
	if (dir < 0)
		my_printf("-");
	for (int i = 0; i != 6; i++) {
		if (nfs->mid >= direction[i].mid_s) {
			my_printf("%s\n", direction[i].set_direction);
			break;
		}
	}
	getline(&buf, &buf_size, stdin);
}

int main(void)
{
	char *buf;
	size_t buf_size = 0;
	nfs_t *nfs = init_nfs();

	my_printf("START_SIMULATION\n");
	getline(&buf, &buf_size, stdin);
	while(1) {
		get_lidar(nfs);
		if (game_end(nfs) == 1)
			break;
		set_speed(nfs);
		get_lidar(nfs);
		if (game_end(nfs) == 1)
			break;
		set_alpha(nfs);
	}
	my_printf("STOP_SIMULATION\n");
	return (0);
}
