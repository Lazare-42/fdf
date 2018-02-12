#include "../includes/fdf.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

void	draw_line(double *from, double *to, int **screen)
{
	double dx;
	double dy;
	double D;
	double y;
	int x;

	dx = from[0] - to[0];
	dy = from[1] - to[1];
	x = from[0];
	y = from[1];
	D = 2 * dy - dx;
	while (x < to[0])
	{
		(*screen)[(int)x + (int)y * X_SIZE] = 0xFEFFFF;
		if (D > 0)
		{
			y++;
			D -= 2 * dx;
		}
		D *= 2 * dy;
	}

}

#include <stdio.h>

void put_to_screen_string(double *tab, int **screen, int print, int *dimensions)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	static	double	*point = NULL;

	if (!point)
	{
		if (!(point = malloc(sizeof(double)*3)))
			exit (0);
	}
	point[0] = tab[0];
	point[1] = tab[1];
	point[2] = tab[2];
	point = matrix_multiplication(point);
	point[0] = point[0] * (X_SIZE / 3) / (dimensions[0]);
	point[1] = point[1] * (Y_SIZE / 3) / (dimensions[1]);
	where_to = point[0] - (int)point[1] * X_SIZE;
	where_to += (X_SIZE / 1 / 3) + (Y_SIZE * 2 / 3) * X_SIZE;
	if (where_to >= 0 && where_to <= max_screen_pixel)
	{
		if (print)
			(*screen)[where_to] = 0xFF255;
		else 
			(*screen)[where_to] = 0;
	}
}

void print_handler(double ***tab, int print, int **screen, int *dimensions)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (print)
				put_to_screen_string(tab[i][j], screen, 1, dimensions);
			else
				put_to_screen_string(tab[i][j], screen, 0, dimensions);
			j++;
		}
		i++;
	}
}
