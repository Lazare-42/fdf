/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:05:04 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/20 11:45:28 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static void	put_screen_str(int x, int y, int **screen, int print)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;

	where_to = 0;
	where_to = x - y * X_SIZE;
	where_to += (X_SIZE / 2) + (Y_SIZE / 2) * X_SIZE;
	if (where_to >= 0 && where_to <= max_screen_pixel)
		(*screen)[where_to] = (print) ? 0xFF400 : 0;
}

static void	draw_line(double *from, double *to, int **screen, int print)
{
	(void)(to);
	put_screen_str((int)from[0], (int)from[1], screen, print);
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
