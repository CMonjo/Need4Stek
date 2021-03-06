/*
** EPITECH PROJECT, 2017
** Leo Library
** File description:
** All the personal library prototypes.
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <string.h>
	#include "leolib.h"

	typedef struct speed_s {
		float mid_s;
		char *set_speed;
		int len;
	} speed_t;

	typedef struct direction_s {
		float mid_s;
		char *set_direction;
		int len;
	} direction_t;

	typedef struct nfs_s {
		char **args;
		float alpha;
		float rays[32];
		float mid;
		float speed;
	} nfs_t;

	int need_to_turn(nfs_t *nfs);
	float get_max(float one, float two);
	float get_min(float one, float two);
	void get_alpha(nfs_t *nfs);
	float my_fabs(float a_max, float a_min);
#endif