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

#include "./minilibx_macos/mlx.h"
#include "./libft/include/libft.h"
#include <unistd.h>
#include "./fdf.h"
#include <stdlib.h>

static float ***g_tab;

int		my_key_funct(int keycode, void *info)
{
	t_mlx *mlx;
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	g_tab = table_transform_handler(g_tab, X_ROTATE_UP);
	print_tab_debug(g_tab);

	keycode++;

	mlx = info;
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx *mlx;
	(void)ac;

	g_tab = NULL;
	mlx = NULL;
	if (av[1])
		g_tab = ft_parsing(av[1]);
	else 
		return(ft_put_fatal_error(("Pass a file to FDF to launch program\n")));
	print_tab_debug(g_tab);
	g_tab = first_camera_move(g_tab);
	if (!(mlx = malloc(sizeof(t_mlx) * 1)))
		return(ft_put_fatal_error(("Malloc error\n")));
		
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, X_SIZE, Y_SIZE, "42");
	mlx->image = mlx_new_image(mlx->mlx, X_SIZE, Y_SIZE);


	if (!(mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0)))
		return ft_put_fatal_error("wft");

	mlx_key_hook(mlx->win, my_key_funct, mlx->mlx);
	mlx_loop(mlx->mlx);

	return (0);
}
