/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/22 12:07:35 by lazrossi         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/include/libft.h"
#include <unistd.h>
#include "../includes/fdf.h"
#include <stdlib.h>

static float ***g_tab = NULL;
static t_mlx *mlx = NULL;

int		my_key_funct(int keycode, void *info)
{
	t_mlx *mlx;
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	table_transform_handler(g_tab, keycode);

	mlx = info;
	mlx++;
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;

	g_tab = NULL;
	mlx = NULL;
	if (av[1])
		g_tab = ft_parsing(av[1]);
	else 
		return(ft_put_fatal_error(("Pass a file to FDF to launch program\n")));
	g_tab = first_camera_move(g_tab);
	if (!(mlx = malloc(sizeof(mlx) * 1)))
		return (0);









	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, X_SIZE, Y_SIZE, "FDF");
	mlx->image = mlx_new_image(mlx->mlx, X_SIZE, Y_SIZE);

	int		bpp;
	int		endian;
	int		size_line;
	mlx->screen_data = (int*)mlx_get_data_addr(mlx->image, &bpp, &size_line, &endian);

	int i;
	int j;
	i = 0;
	j = 0;
	while (g_tab[i])
	{
		j = 0;
		while(g_tab[i][j])
		{
			put_to_screen_string(g_tab[i][j], &(mlx->screen_data));
			if (g_tab[i][1 + j])
			{
				NULL;
			}
			if (g_tab[i + 1])
			{
			//	draw_line(g_tab[i][j], g_tab[i + 1][j], &(mlx->screen_data));
			}
			j++;
		}
		i++;
	}
	debug();
	ft_putchar('\n');
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);

	mlx_key_hook(mlx->win, my_key_funct, mlx->mlx);
	mlx_loop(mlx->mlx);

	return (0);
}
