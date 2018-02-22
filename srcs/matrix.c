/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:32:13 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 16:18:46 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double	***matrix_multiplication(double ***tab, int *dimensions)
{
	int		i;
	int		j;
	double	*cos_sinus;

	i = -1;
	cos_sinus = set_get_cos_sinus(NULL);
//	printf("%g\n", set_get_zoom_x(0));
//	printf("%g\n", set_get_zoom_y(0));
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			tab[i][j][0] = (cos_sinus[2] * (cos_sinus[5] * tab[i][j][1] +
					cos_sinus[4] * tab[i][j][0]) - cos_sinus[3] * tab[i][j][2]);
			tab[i][j][1] = cos_sinus[1] * (cos_sinus[2] * tab[i][j][2] +
	cos_sinus[3] * (cos_sinus[5] * tab[i][j][1] + cos_sinus[4] * tab[i][j][0]
)) + cos_sinus[0] * (cos_sinus[4] * tab[i][j][1] - cos_sinus[5] * tab[i][j][0]);
			tab[i][j][2] = cos_sinus[0] * (cos_sinus[2] * tab[i][j][2] +
			cos_sinus[3] * (cos_sinus[5] * tab[i][j][1] + cos_sinus[4] *
			tab[i][j][0])) - cos_sinus[1] * (cos_sinus[4] * tab[i][j][1] -
			cos_sinus[5] * tab[i][j][0]);

			tab[i][j][0] = tab[i][j][0] * (set_get_zoom_x(0)) / (dimensions[0]);
			tab[i][j][1] = tab[i][j][1] * (set_get_zoom_y(0)) / (dimensions[1]);

		}
	}
	return (tab);
}

void	negative_radius_value(int input_operation)
{
	double *radiuses;

	radiuses = set_get_radiuses(NULL);
	if (input_operation == X_ROTATE_DOWN)
	{
		if (radiuses[0] - 0.05 < 0)
			radiuses[0] += M_PI * 2 - 0.05;
		else
			radiuses[0] -= 0.05;
	}
	else if (input_operation == Y_ROTATE_DOWN)
	{
		if (radiuses[1] - 0.05 < 0)
			radiuses[1] += M_PI * 2 - 0.05;
		else
			radiuses[1] -= 0.05;
	}
	else if (input_operation == Z_ROTATE_DOWN)
	{
		if (radiuses[2] - 0.05 < 0)
			radiuses[2] += M_PI * 2 - 0.05;
		else
			radiuses[1] -= 0.05;
	}
	set_get_radiuses(radiuses);
}

void	modify_sin_cos(int input_operation)
{
	double *cos_sinus;
	double *radiuses;

	radiuses = set_get_radiuses(NULL);
	cos_sinus = set_get_cos_sinus(NULL);
	if (input_operation == X_ROTATE_UP || input_operation == X_ROTATE_DOWN)
	{
		cos_sinus[0] = cos(radiuses[0]);
		cos_sinus[1] = sin(radiuses[0]);
	}
	else if (input_operation == Y_ROTATE_UP || input_operation == Y_ROTATE_DOWN)
	{
		cos_sinus[2] = cos(radiuses[1]);
		cos_sinus[3] = sin(radiuses[1]);
	}
	else if (input_operation == Z_ROTATE_UP || input_operation == Z_ROTATE_DOWN)
	{
		cos_sinus[4] = cos(radiuses[2]);
		cos_sinus[5] = sin(radiuses[2]);
	}
	set_get_cos_sinus(cos_sinus);
	set_get_radiuses(radiuses);
}

void	modify_radiuses(int input_operation)
{
	double *cos_sinus;
	double *radiuses;

	radiuses = set_get_radiuses(NULL);
	cos_sinus = set_get_cos_sinus(NULL);
	(input_operation == X_ROTATE_UP) ? radiuses[0] += 0.05 : 0;
	(input_operation == Y_ROTATE_UP) ? radiuses[1] += 0.05 : 0;
	(input_operation == Z_ROTATE_UP) ? radiuses[2] += 0.05 : 0;
	if (input_operation == X_ROTATE_DOWN || input_operation == Y_ROTATE_DOWN ||
			input_operation == Z_ROTATE_DOWN)
		negative_radius_value(input_operation);
	set_get_cos_sinus(cos_sinus);
	set_get_radiuses(radiuses);
	modify_sin_cos(input_operation);
}

double	***table_transform_handler(double ***tab, int input_operation)
{
	double *cos_sinus;
	double *radiuses;

	cos_sinus = set_get_cos_sinus(NULL);
	radiuses = set_get_radiuses(NULL);
	if (!(check_if_input(input_operation)))
		return (tab);
	if (input_operation == CAMERA_SETBACK)
	{
		radiuses[0] = acos(cos_sinus[0]);
		radiuses[1] = acos(cos_sinus[2]);
		radiuses[2] = acos(cos_sinus[4]);
	}
	else if (input_operation == KEY_LEFT || input_operation == KEY_RIGHT ||
			input_operation == KEY_DOWN || input_operation == KEY_UP)
	{
		tab = camera_move(tab, input_operation, &cos_sinus);
		radiuses[0] = acos(cos_sinus[0]);
		radiuses[1] = acos(cos_sinus[2]);
		radiuses[2] = acos(cos_sinus[4]);
	}
	else if (input_operation == ZOOM_IN || input_operation == ZOOM_OUT)
		zoom_handler(input_operation);
	else
		modify_radiuses(input_operation);
	set_get_radiuses(radiuses);
	return (tab);
}
