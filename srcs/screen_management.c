/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:05:04 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/20 15:06:31 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	draw_line(double *from, double *to, int **screen, int print)
{
	double	t;
	double	y;
	double	x;
	double	tmp[3];

	t = 0;
	int steep;

	steep = 0;
	if ((from[0] - to[0]) < (from[1] - to[1]))
	{
		tmp[0] = from[0];
		from[0] = from[1];
		from[1] = tmp[0];

		tmp[0] = to[0];
		to[0] = to[1];
		to[1] = tmp[0];
		steep = 1;
	}
	if (from[0] > to[0])
	{
		tmp[0] = from[0];
		from[0] = to[0];
		to[0] = tmp[0];


		tmp[1] = from[1];
		from[1] = to[1];
		to[1] = tmp[1];
	}
	x = from[0];
	while (x <= to[0])
	{
		x++;
		t = (x - from[0]) / (to[0] - from[0]);
		y = from[1] * (1 - t) + to[1] * t;
		if (steep)
		{
			point[0] = y;
			point[1] = x;
		}
		else
		{
			point[0] = x;
			point[1] = y;
		}
		put_screen_str(screen, print);
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
			if (tab[i + 1] && tab[i + 1][j])
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
		ft_tabdel((void**)tab);
	//ft_memdel((void**)&tab[i][j]);
}
