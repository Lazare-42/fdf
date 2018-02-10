/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:07:08 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/22 12:07:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../libft/include/libft.h"
#include <unistd.h>
#include "../includes/fdf.h"
#include <stdlib.h>

static double ***g_tab = NULL;
static t_mlx mlx;

int		my_key_funct(int keycode)
{
	print_handler(g_tab, 0, &(mlx.screen_data));
	g_tab = table_transform_handler(g_tab, keycode, NULL);
	print_handler(g_tab, 1, &(mlx.screen_data));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	int		bpp;
	int		endian;
	int		size_line;

	g_tab = NULL;
	if (av[1])
		g_tab = ft_parsing(av[1]);
	else 
		return(ft_put_fatal_error(("Pass a file to FDF to launch program\n")));
//	g_tab = first_camera_move(g_tab);

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "FDF");
	mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE);

	mlx.screen_data = (int*)mlx_get_data_addr(mlx.image, &bpp, &size_line, &endian);
	print_handler(g_tab, 1, &(mlx.screen_data));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	mlx_key_hook(mlx.win, my_key_funct, mlx.mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
