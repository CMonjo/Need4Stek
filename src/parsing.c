/*
** EPITECH PROJECT, 2017
** nfs_package
** File description:
** ia.c
*/

#include "main.h"

int need_to_turn(nfs_t *nfs)
{
	if (nfs->mid < 1000)
		return (0);
	else
		return (1);
}

float get_max(float one, float two)
{
	if (one > two)
		return (one);
	else
		return (two);
}

float get_min(float one, float two)
{
	if (one < two)
		return (one);
	else
		return (two);
}

float my_fabs(float a_min, float a_max)
{
	float tmp = 1;
	float calc = 0;

	if (a_max != 0)
		tmp = a_max;
	calc = a_min * 100 / tmp;
	if (calc < 0)
		calc *= -1;
	return (calc);
}

float put_alpha(float alpha, float max_dir, float right, float left)
{
	if (alpha > 120) {
		if (right < left)
			return (max_dir);
		else
			return (max_dir *= -1);
	}
	if (alpha < 70 || alpha > 130) {
		if (right < left)
			return (max_dir);
		else
			return (max_dir *= - 1);
	}
	return (0);
}

void get_alpha(nfs_t *nfs)
{
	float max_dir = (1 - nfs->speed) / 3;
	float range_average = 3;
	float left = nfs->rays[0];
	float right = nfs->rays[31];
	float a_max = 0;
	float a_min = 0;

	if (need_to_turn(nfs) == 1) {
		nfs->alpha = 0;
		return;
	}
	for (int i = 0; i != range_average; i ++) {
		left += nfs->rays[i];
		left /= 2;
	}
	for (int i = 31 - range_average; i != 31; i++) {
		right += nfs->rays[i];
		right /= 2;
	}
	a_max = get_max(left, right);
	a_min = get_min(left, right);
	nfs->alpha = my_fabs(a_min, a_max);
	nfs->alpha = put_alpha(nfs->alpha, max_dir, right, left);
}
