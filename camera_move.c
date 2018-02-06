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

	i = 0;
	x_setback = X_SIZE / 3; 
	z_setback = Y_SIZE / 3;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			tab[i][j][0] -= x_setback;
			tab[i][j][2] -= z_setback;
			j++;
		}
		i++;
	}
	return (tab);
}
