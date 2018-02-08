#include "fdf.h"

float	***camera_move(float ***tab, int input_operation)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			tab[i][j][2] = (input_operation == KEY_UP) ? tab[i][j][2]++ : tab[i][j][2];
			tab[i][j][2] = (input_operation == KEY_DOWN) ? tab[i][j][2]-- : tab[i][j][2];
			tab[i][j][1] = (input_operation == KEY_LEFT) ? tab[i][j][1]++ : tab[i][j][1];
			tab[i][j][1] = (input_operation == KEY_LEFT) ? tab[i][j][1]-- : tab[i][j][1];
			j++;
		}
		i++;
	}
	return (tab);
}

float	***first_camera_move(float ***tab)
{
	int i;
	int j;
	int x_setback;
	int z_setback;
	int y_setback;

	i = -1;
	x_setback = 0; 
	z_setback = 0;
	y_setback = 0;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			(tab[i][j][0] > x_setback) ? x_setback = tab[i][j][0]: 0;
			(tab[i][j][1] > y_setback) ? y_setback = tab[i][j][1]: 0;
			(tab[i][j][2] > z_setback) ? z_setback = tab[i][j][2]: 0;
		}
	}
	i = -1;
	x_setback++;
	z_setback++;
	y_setback *= 3;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			tab[i][j][0] += x_setback;
			tab[i][j][1] += y_setback;
		}
	}
	return (tab);
}
