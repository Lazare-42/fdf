#include "../includes/fdf.h"
#include "../libft/include/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/*
*** Note : g_cos_sinus is filled up in the x, y, z and cosinus-sinus order
*/

static float g_cos_sinus[6] = {1, 0, 1, 0, 1, 0};
static float ***g_rotate_matrix = NULL;
static float x_radius = 0;
static float y_radius = 0;
static float z_radius = 0;

float	*matrix_multiplication(float *tab)
{
	tab[0] = g_rotate_matrix[0][0][0] * tab[0] + g_rotate_matrix[0][0][1] * tab[1] + g_rotate_matrix[0][0][2] * tab[2];
	tab[1] = g_rotate_matrix[0][1][0] * tab[0] + g_rotate_matrix[0][1][1] * tab[1] + g_rotate_matrix[0][1][2] * tab[2];
	tab[2] = g_rotate_matrix[0][2][0] * tab[0] + g_rotate_matrix[0][2][1] * tab[1] + g_rotate_matrix[0][2][2] * tab[2];

	tab[0] = g_rotate_matrix[1][0][0] * tab[0] + g_rotate_matrix[1][0][1] * tab[1] + g_rotate_matrix[1][0][2] * tab[2];
	tab[1] = g_rotate_matrix[1][1][0] * tab[0] + g_rotate_matrix[1][1][1] * tab[1] + g_rotate_matrix[1][1][2] * tab[2];
	tab[2] = g_rotate_matrix[1][2][0] * tab[0] + g_rotate_matrix[1][2][1] * tab[1] + g_rotate_matrix[1][2][2] * tab[2];

	tab[0] = g_rotate_matrix[2][0][0] * tab[0] + g_rotate_matrix[2][0][1] * tab[1] + g_rotate_matrix[2][0][2] * tab[2];
	tab[1] = g_rotate_matrix[2][1][0] * tab[0] + g_rotate_matrix[2][1][1] * tab[1] + g_rotate_matrix[2][1][2] * tab[2];
	tab[2] = g_rotate_matrix[2][2][0] * tab[0] + g_rotate_matrix[2][2][1] * tab[1] + g_rotate_matrix[2][2][2] * tab[2];

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
*** Note : filling up the float *** matrix in the order of the matrix_multiplication
*** Note : filling up the float ** matrixes in vertical-vector order
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

float	***table_transform_handler(float ***tab, int input_operation)
{
	int i;
	int j;

	i = 0;
	if (!g_rotate_matrix)
		if (!(g_rotate_matrix = create_rotation_matrix(g_rotate_matrix)))
			return (NULL);
	if (input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP)
		tab = camera_move(tab, input_operation);
	if (input_operation == X_ROTATE_DOWN || input_operation == X_ROTATE_UP ||
		input_operation == Y_ROTATE_DOWN || input_operation == Y_ROTATE_UP ||
		input_operation == Z_ROTATE_DOWN || input_operation == Z_ROTATE_UP)
		modify_sin_cos(input_operation);
	print_tab_debug(tab);
	fillup_rotation_matrix(input_operation);
	while (tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			tab[i][j] = matrix_multiplication(tab[i][j]);
			j++;
		}
		i++;
	}
	return (tab);
}
