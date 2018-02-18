#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/*
 *** Note : g_cos_sinus is filled up in the x, y, z and cosinus-sinus order
 */

static double *g_cos_sinus  = NULL;
static double x_radius = 0;
static double y_radius = 0;
static double z_radius = 0;

double	*matrix_multiplication(double *tab)
{
	X = (cy * (sz * Y + cz * X) - sy * Z);
	Y = sx * (cy * Z + sy * (sz * Y + cz * X)) + cx * (cz * Y - sz * X);
	Z = cx * (cy * Z + sy * (sz * Y + cz * X)) - sx * (cz * Y - sz * X);
//	X /= Z;
//	Y /= Z;
	return (tab);
}

void	negative_radius_value(int input_operation)
{
	if (input_operation == X_ROTATE_DOWN)
	{
		if (x_radius - 0.05 < 0)
			x_radius += M_PI * 2 - 0.05;
		else
			x_radius -= 0.05;
	}
	else if (input_operation == Y_ROTATE_DOWN)
	{
		if (y_radius - 0.05 < 0)
			y_radius += M_PI * 2 - 0.05;
		else
			y_radius -= 0.05;
	}
	else if (input_operation == Z_ROTATE_DOWN)
	{
		if (z_radius - 0.05 < 0)
			z_radius += M_PI * 2 - 0.05;
		else
			y_radius -= 0.05;
	}
}

void	modify_sin_cos(int input_operation)
{
	x_radius = (input_operation == X_ROTATE_UP) ? x_radius + 0.05 : x_radius;
	y_radius = (input_operation == Y_ROTATE_UP) ? y_radius + 0.05 : y_radius;
	z_radius = (input_operation == Z_ROTATE_UP) ? z_radius + 0.05 : z_radius;
	if (input_operation == X_ROTATE_DOWN || input_operation == Y_ROTATE_DOWN ||
			input_operation == Z_ROTATE_DOWN)
		negative_radius_value(input_operation);
	if (input_operation == X_ROTATE_UP || input_operation == X_ROTATE_DOWN)
	{
		cx = cos(x_radius);
		sx = sin(x_radius);
	}
	else if (input_operation == Y_ROTATE_UP || input_operation == Y_ROTATE_DOWN)
	{
		cy = cos(y_radius);
		sy = sin(y_radius);
	}
	else if (input_operation == Z_ROTATE_UP || input_operation == Z_ROTATE_DOWN)
	{
		cz = cos(z_radius);
		sz = sin(z_radius);
	}
}

int		check_if_input(int input_operation)
{
	if (input_operation == X_ROTATE_DOWN || input_operation == X_ROTATE_UP ||
			input_operation == Y_ROTATE_DOWN || input_operation == Y_ROTATE_UP ||
			input_operation == Z_ROTATE_DOWN || input_operation == Z_ROTATE_UP ||
			input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP ||
			input_operation == CAMERA_SETBACK)
		return (1);
	else
		return (0);
}

double	***table_transform_handler(double ***tab, int input_operation, int *field_size)
{
	if (!(check_if_input(input_operation)))
		return (tab);
	if (!g_cos_sinus)
	{
		if (!(g_cos_sinus = (double*)malloc(sizeof(double) * 6)))
			return (NULL);
		(g_cos_sinus)[0] = 1;
		(g_cos_sinus)[1] = 0;
		(g_cos_sinus)[2] = 1;
		(g_cos_sinus)[3] = 0;
		(g_cos_sinus)[4] = 1;
		(g_cos_sinus)[5] = 0;
	}
	if (input_operation == CAMERA_SETBACK)
	{
	//	tab = first_camera_move(tab, &g_cos_sinus, field_size); 
		modify_sin_cos(g_cos_sinus);
		x_radius = acos(g_cos_sinus[0]);
		y_radius = acos(g_cos_sinus[2]);
		z_radius = acos(g_cos_sinus[4]);
	}
	else if (input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP)
	{
		tab = camera_move(tab, input_operation, &g_cos_sinus);
		x_radius = acos(g_cos_sinus[0]);
		y_radius = acos(g_cos_sinus[2]);
		z_radius = acos(g_cos_sinus[4]);
	}
	else
	{
		// this else leaves only the conditions for axis tilting
		modify_sin_cos(input_operation);
	}
	return (tab);
}
