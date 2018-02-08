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

void put_to_screen_string(double *tab, int **screen)
{
	int where_to;

	where_to = (int)tab[0] + (tab[2]) * Y_SIZE;
	(*screen)[where_to] = 0xFEFFFF;
}
