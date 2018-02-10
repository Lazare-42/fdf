#include "../includes/fdf.h"
#include "../libft/include/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/*
 *** Note : g_cos_sinus is filled up in the x, y, z and cosinus-sinus order
 */

static double *g_cos_sinus  = NULL;
static double ***g_rotate_matrix = NULL;
static double x_radius = 0;
static double y_radius = 0;
static double z_radius = 0;

double	***matrix_multiplication(double ***tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			tab[i][j][0] = g_rotate_matrix[0][0][0] * tab[i][j][0] + g_rotate_matrix[0][0][1] * tab[i][j][1] + g_rotate_matrix[0][0][2] * tab[i][j][2];
			tab[i][j][1] = g_rotate_matrix[0][1][0] * tab[i][j][0] + g_rotate_matrix[0][1][1] * tab[i][j][1] + g_rotate_matrix[0][1][2] * tab[i][j][2];
			tab[i][j][2] = g_rotate_matrix[0][2][0] * tab[i][j][0] + g_rotate_matrix[0][2][1] * tab[i][j][1] + g_rotate_matrix[0][2][2] * tab[i][j][2];

			tab[i][j][0] = g_rotate_matrix[1][0][0] * tab[i][j][0] + g_rotate_matrix[1][0][1] * tab[i][j][1] + g_rotate_matrix[1][0][2] * tab[i][j][2];
			tab[i][j][1] = g_rotate_matrix[1][1][0] * tab[i][j][0] + g_rotate_matrix[1][1][1] * tab[i][j][1] + g_rotate_matrix[1][1][2] * tab[i][j][2];
			tab[i][j][2] = g_rotate_matrix[1][2][0] * tab[i][j][0] + g_rotate_matrix[1][2][1] * tab[i][j][1] + g_rotate_matrix[1][2][2] * tab[i][j][2];

			tab[i][j][0] = g_rotate_matrix[2][0][0] * tab[i][j][0] + g_rotate_matrix[2][0][1] * tab[i][j][1] + g_rotate_matrix[2][0][2] * tab[i][j][2];
			tab[i][j][1] = g_rotate_matrix[2][1][0] * tab[i][j][0] + g_rotate_matrix[2][1][1] * tab[i][j][1] + g_rotate_matrix[2][1][2] * tab[i][j][2];
			tab[i][j][2] = g_rotate_matrix[2][2][0] * tab[i][j][0] + g_rotate_matrix[2][2][1] * tab[i][j][1] + g_rotate_matrix[2][2][2] * tab[i][j][2];
			j++;
		}
		i++;
	}
	return (tab);
}

void	negative_radius_value(int input_operation)
{
	if (input_operation == X_ROTATE_DOWN)
	{
		if (x_radius - 0.002 < 0)
			x_radius += M_PI * 2 - 0.002;
		else
			x_radius -= 0.002;
	}
	else if (input_operation == X_ROTATE_DOWN)
	{
		if (x_radius - 0.002 < 0)
			x_radius += M_PI * 2 - 0.002;
		else
			x_radius -= 0.002;
	}
	else if (input_operation == X_ROTATE_DOWN)
	{
		if (x_radius - 0.002 < 0)
			x_radius += M_PI * 2 - 0.002;
		else
			x_radius -= 0.002;
	}
}

void	modify_sin_cos(int input_operation)
{
	x_radius = (input_operation == X_ROTATE_UP) ? x_radius + 0.005 : x_radius;
	y_radius = (input_operation == Y_ROTATE_UP) ? y_radius + 0.005 : y_radius;
	z_radius = (input_operation == Z_ROTATE_UP) ? z_radius + 0.005 : z_radius;
	if (input_operation == X_ROTATE_DOWN || input_operation == Y_ROTATE_DOWN ||
			input_operation == Z_ROTATE_DOWN)
		negative_radius_value(input_operation);
	if (input_operation == X_ROTATE_UP || input_operation == X_ROTATE_DOWN)
	{
		g_cos_sinus[0] = cos(x_radius);
		g_cos_sinus[1] = sqrt(1 - g_cos_sinus[0] * g_cos_sinus[0]);
	}
	else if (input_operation == Y_ROTATE_UP || input_operation == Y_ROTATE_DOWN)
	{
		g_cos_sinus[2] = cos(y_radius);
		g_cos_sinus[3] = sqrt(1 - g_cos_sinus[2] * g_cos_sinus[2]);
	}
	else if (input_operation == Z_ROTATE_UP || input_operation == Z_ROTATE_DOWN)
	{
		g_cos_sinus[4] = cos(z_radius);
		g_cos_sinus[5] = sqrt(1 - g_cos_sinus[4] * g_cos_sinus[4]);
	}
}

/*
 *** Note : filling up the double *** matrix in the order of the matrix_multiplication
 *** Note : filling up the double ** matrixes in vertical-vector order
 */

void	fillup_rotation_matrix(int input_operation)
{
	static int first = 1;

	if (first || input_operation == Z_ROTATE_DOWN || input_operation == Z_ROTATE_UP)
	{
		g_rotate_matrix[0][0][0] = g_cos_sinus[4];
		g_rotate_matrix[0][0][1] = -g_cos_sinus[5];
		g_rotate_matrix[0][1][0] = g_cos_sinus[5];
		g_rotate_matrix[0][1][1] = g_cos_sinus[4];
		g_rotate_matrix[0][2][2] = 1;
	}
	if (first || input_operation == Y_ROTATE_DOWN || input_operation == Y_ROTATE_UP)
	{
		g_rotate_matrix[1][0][0] = g_cos_sinus[2];
		g_rotate_matrix[1][0][2] = g_cos_sinus[3];
		g_rotate_matrix[1][1][1] = 1;
		g_rotate_matrix[1][2][0] = -g_cos_sinus[3];
		g_rotate_matrix[1][2][2] = g_cos_sinus[2];
	}
	if (first || input_operation == X_ROTATE_DOWN || input_operation == X_ROTATE_UP)
	{
		g_rotate_matrix[2][0][0] = 1;
		g_rotate_matrix[2][1][1] = g_cos_sinus[0];
		g_rotate_matrix[2][1][2] = -g_cos_sinus[1];
		g_rotate_matrix[2][2][1] = g_cos_sinus[1];
		g_rotate_matrix[2][2][2] = g_cos_sinus[0];
	}
	first = 0;
}

double	***table_transform_handler(double ***tab, int input_operation, int *field_size)
{
	if (!(g_cos_sinus = (double*)malloc(sizeof(double) * 6)))
		return (NULL);
	if (!g_rotate_matrix)
		if (!(g_rotate_matrix = create_rotation_matrix(g_rotate_matrix)))
			return (NULL);
	if (input_operation == CAMERA_SETBACK)
		tab = first_camera_move(tab, &g_cos_sinus, field_size); 
	if (input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP)
		tab = camera_move(tab, input_operation, &g_cos_sinus);
	if (input_operation == X_ROTATE_DOWN || input_operation == X_ROTATE_UP ||
			input_operation == Y_ROTATE_DOWN || input_operation == Y_ROTATE_UP ||
			input_operation == Z_ROTATE_DOWN || input_operation == Z_ROTATE_UP)
		modify_sin_cos(input_operation);
	fillup_rotation_matrix(input_operation);
	tab = matrix_multiplication(tab);
	return (tab);
}
