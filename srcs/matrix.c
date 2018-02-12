#include "../includes/fdf.h"
#include "../libft/include/libft.h"
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
			X = (cy * (sz * Y + cz * X) - sy * Z);
			Y = sx * (cy * Z + sy * (sz * Y + cz * X)) + cx * (cz * Y - sz * X);
			Z = cx * (cy * Z + sy * (sz * Y + cz * X)) - sx * (cz * Y - sz * X);
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
		cx = cos(x_radius);
		sx = sqrt(1 - cx * cx);
	}
	else if (input_operation == Y_ROTATE_UP || input_operation == Y_ROTATE_DOWN)
	{
		cy = cos(y_radius);
		sy = sqrt(1 - cy * cy);
	}
	else if (input_operation == Z_ROTATE_UP || input_operation == Z_ROTATE_DOWN)
	{
		cz = cos(z_radius);
		sz = sqrt(1 - cz * cz);
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
	if (!(g_cos_sinus = (double*)malloc(sizeof(double) * 6)))
		return (NULL);
	if (input_operation == CAMERA_SETBACK)
	{
		ft_putstr("go back\n");
		tab = translate(tab, &g_cos_sinus, field_size);
		tab = matrix_multiplication(tab);
		tab = first_camera_move(tab, &g_cos_sinus, field_size); 
	}
	else if (input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP)
	{
		ft_putstr("key\n");
		tab = camera_move(tab, input_operation, &g_cos_sinus);
	}
	else
	{
		ft_putstr("sin_cos\n");
		modify_sin_cos(input_operation);
	}
	printf("\n%G\n", g_cos_sinus[0]);
	printf("%G\n", g_cos_sinus[1]);
	printf("%G\n", g_cos_sinus[2]);
	printf("%G\n", g_cos_sinus[3]);
	printf("%G\n", g_cos_sinus[4]);
	printf("%G\n", g_cos_sinus[5]);
	tab = matrix_multiplication(tab);
	return (tab);
}
