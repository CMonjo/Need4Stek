/*
** EPITECH PROJECT, 2017
** nfs_package
** File description:
** ia.c
*/

#include "need_four_stek.h"

void set_alpha(nfs_t *nfs);
void set_speed(nfs_t *nfs);
void get_lidar(nfs_t *nfs);
int game_end(char *buffer);
nfs_t *init_nfs(void);

int main(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	nfs_t *nfs = init_nfs();

	write(1, "START_SIMULATION\n", 17);
	if (getline(&buf, &buf_size, stdin) == -1)
		return (84);
	game_end(buf);
	while (1) {
		get_lidar(nfs);
		set_alpha(nfs);
		get_lidar(nfs);
		set_speed(nfs);
	}
	return (0);
}
