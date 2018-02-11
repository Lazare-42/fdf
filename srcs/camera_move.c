#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include "../libft/include/libft.h"

// setback est la taille des reculs par rapport a la position 0,0,0 - donne ainsi
// les angles de rotation pour chaque cote 
static int setback[3];
//** edge veut dire arete (du vecteur de mouvement)
static double edge;

static void	modify_sin_cos(double **g_cos_sinus)
{
	edge = sqrt(setback[0] * setback[0] + setback[1] * setback[1] + setback[2] * setback[2]);
	(*g_cos_sinus)[0] = setback[0] / edge;
	(*g_cos_sinus)[1] = sqrt(1 - (*g_cos_sinus)[0] * (*g_cos_sinus)[0]);
	(*g_cos_sinus)[2] = setback[1] / edge;
	(*g_cos_sinus)[3] = sqrt(1 - (*g_cos_sinus)[2] * (*g_cos_sinus)[2]);
	(*g_cos_sinus)[4] = setback[2] / edge;
	(*g_cos_sinus)[5] = sqrt(1 - (*g_cos_sinus)[4] * (*g_cos_sinus)[4]);
}

double	***camera_move(double ***tab, int input_operation, double **g_cos_sinus)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			//si tu zoomes tu rapproches de lobjet donc --
			Z = (input_operation == KEY_UP) ? Z-- : Z;
			Z = (input_operation == KEY_DOWN) ? Z++ : Z;
			Y = (input_operation == KEY_LEFT) ? Y-- : Y;
			Y = (input_operation == KEY_RIGHT) ? Y++ : Y;
		}
	}
	(input_operation == KEY_UP) ? setback[2]++ : 0;
	(input_operation == KEY_DOWN) ? setback[2]-- : 0;
	(input_operation == KEY_LEFT) ? setback[1]++ : 0;
	(input_operation == KEY_RIGHT) ? setback[1]-- : 0;
	modify_sin_cos(g_cos_sinus);
	return (tab);
}

double	***first_camera_move(double ***tab, double **g_cos_sinus, int *field_size)
{
	int i;
	int j;

	i = -1;
	setback[0] = field_size[0] * 2;
	setback[1] = field_size[1] * 3;
	setback[2] = field_size[2] * 2;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			X += setback[0];
			//X *= X_SIZE / setback[0];
			Y += setback[1];
		//	Y *= Y_SIZE / setback[0];
			Z += setback[2];
		}
	}
	modify_sin_cos(g_cos_sinus);
	return (tab);
}
