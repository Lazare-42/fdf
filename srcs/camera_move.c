#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include "../libft/include/libft.h"

static int setback[3];
//** edge veut dire arete (du vecteur de mouvement)
static float edge;

static void	modify_sin_cos(double **cos_sinus)
{
	(*cos_sinus)[0] = setback[0] / edge;
	(*cos_sinus)[1] = sqrt(1 - (*cos_sinus)[0] * (*cos_sinus)[0]);
	(*cos_sinus)[2] = setback[1] / edge;
	(*cos_sinus)[3] = sqrt(1 - (*cos_sinus)[2] * (*cos_sinus)[2]);
	(*cos_sinus)[4] = setback[2] / edge;
	(*cos_sinus)[5] = sqrt(1 - (*cos_sinus)[4] * (*cos_sinus)[4]);
}

double	***camera_move(double ***tab, int input_operation, double **cos_sinus)
{
	(void)cos_sinus;
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
			tab[i][j][1] = (input_operation == KEY_RIGHT) ? tab[i][j][1]-- : tab[i][j][1];
			j++;
		}
		i++;
	}
	(input_operation == KEY_UP) ? setback[2]++ : 0;
	(input_operation == KEY_DOWN) ? setback[2]-- : 0;
	(input_operation == KEY_LEFT) ? setback[1]++ : 0;
	(input_operation == KEY_RIGHT) ? setback[1]-- : 0;
	modify_sin_cos(cos_sinus);
	return (tab);
}

double	***first_camera_move(double ***tab, double **cos_sinus, int *field_size)
{
	int i;
	int j;

	i = 0;
	setback[0] = field_size[0] * 2;
	setback[1] = field_size[1] * 3;
	setback[2] = field_size[2] * 2;
	edge = sqrt(setback[0] * setback[0] + setback[1] * setback[1] + setback[2] * setback[2]);
	// Pas sur d'avoir a reculer. Car je veux juste avoir de vue - pas reculer en l'occurence ! Surtout que je veux ensuite avoir 0.0.0
	// au centre de l'ecran
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			tab[i][j][0] += setback[0];
			tab[i][j][1] += setback[1];
			tab[i][j][2] += setback[2];
			j++;
		}
		i++;
	}
	modify_sin_cos(cos_sinus);
	return (tab);
}
