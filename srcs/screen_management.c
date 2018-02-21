#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static	double point[3];

static void	put_screen_str(int **screen, int print)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;

	where_to = 0;
	where_to = (int)point[0] - (int)point[1] * X_SIZE;
	where_to += (X_SIZE / 2) + (Y_SIZE / 2) * X_SIZE;
	if (where_to >= 0 && where_to <= max_screen_pixel)
		(*screen)[where_to] = (print) ? 0xFF400 : 0;
}

#include <stdio.h>

void	draw_line(double *from, double *to, int **screen, int print)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;

	point[0] = (int)from[0];
	point[1] = (int)from[1];
	dx = (int)(to[0] - from[0]);
	dy = (int)(to[1] - from[1]);
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	put_screen_str(screen, print);
	i = 1;
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i <= dx)
		{
			point[0] += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				point[1] += yinc;
			}
			put_screen_str(screen, print);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		while(i <= dy)
		{
			point[1] += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				point[0] += xinc;
			}
			put_screen_str(screen, print);
			i++;
		}
	}
}

static void	put_to_screen_string(double ***tab, int **screen, int print, int *dimensions)
{
	int			i;
	int			j;

	i = -1;
	tab	= matrix_multiplication(tab, dimensions);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j + 1])
				draw_line(tab[i][j], tab[i][j + 1], screen, print);
			if (tab[i + 1])
				draw_line(tab[i][j], tab[i + 1][j], screen, print);
			point[0] = tab[i][j][0];
			point[1] = tab[i][j][1];
			put_screen_str(screen, print);
		}
	}
}

void	print_handler(double ***tabtab, int print, int **screen, int *dimensions)
{
	int		i;
	double	***tab;

	tab = NULL;
	i = -1;
	if (!(tab = create_temp_tab(dimensions, tabtab)))
		ft_myexit("Malloc error");
	if (print)
		put_to_screen_string(tab, screen, 1, dimensions);
	else
		put_to_screen_string(tab, screen, 0, dimensions);
	while (tab[++i])
		ft_tabdel((void***)&(tab[i]));
	free(tab);
}
