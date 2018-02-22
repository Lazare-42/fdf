/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:20:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 12:43:55 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

void		put_screen_str(int **screen, int print)
{
	int			where_to;
	static	int	max_screen_pixel = X_SIZE * Y_SIZE;
	double		*point;

	point = set_get_pixel(NULL);
	where_to = 0;
	where_to = (int)point[0] - (int)point[1] * X_SIZE;
	where_to += location_handler(0);
	if (where_to >= 0 && where_to <= max_screen_pixel)
		(*screen)[where_to] = (print) ? 0xFF400 : 0;
}

static void	put_to_screen_string(double ***tab, int **screen,
		int print, int *dimensions)
{
	int			i;
	int			j;
	double		*point;

	point = set_get_pixel(NULL);
	i = -1;
	tab = matrix_multiplication(tab, dimensions);
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
	set_get_pixel(point);
}

void		print_handler(double ***tabtab,
		int print, int **screen, int *dimensions)
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
