#include "../includes/fdf.h"
#include "../libft/include/libft.h"

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
	static int	max_screen_pixel = X_SIZE * Y_SIZE;
	ft_putnbr(dimensions[0]);

	tab[0] *= (X_SIZE / 3) / (dimensions[0]);
	tab[1] *= (Y_SIZE / 3) / (dimensions[1] * 4);
	where_to = tab[0] - (int)tab[1] * X_SIZE;
	where_to += (X_SIZE / 2) + (Y_SIZE / 2) * X_SIZE;
	if (where_to >= 0 && where_to <= max_screen_pixel)
	{
		if (print)
			(*screen)[where_to] = 0xFEFFBFF;
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
