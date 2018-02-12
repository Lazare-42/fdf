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

int		redraw(int keycode, int *dimensions)
{
	ft_putnbr(keycode);
	ft_putchar(' ');
	if (keycode == 53)
		exit(0);
	print_handler(g_tab, 0, &(mlx.screen_data), dimensions);
	g_tab = table_transform_handler(g_tab, keycode, NULL);
	print_handler(g_tab, 1, &(mlx.screen_data), dimensions);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	int		bpp;
	int		endian;
	int		size_line;
	int		*dimensions;
	int 	keycode;

	keycode = 0;
	g_tab = NULL;
	dimensions = NULL;
	if (av[1])
	{
		if (!(g_tab = ft_parsing(av[1], &dimensions)))
			return (ft_put_fatal_error("Parsing error."));
	}
	else 
		return(ft_put_fatal_error(("Pass a file to FDF to launch program")));

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, X_SIZE, Y_SIZE, "FDF");
	mlx.image = mlx_new_image(mlx.mlx, X_SIZE, Y_SIZE);
	mlx.screen_data = (int*)mlx_get_data_addr(mlx.image, &bpp, &size_line, &endian);

	print_handler(g_tab, 1, &(mlx.screen_data), dimensions);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	mlx_key_hook(mlx.win, redraw, dimensions);
	mlx_loop(mlx.mlx);

	return (0);
}
