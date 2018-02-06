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
#include <stdio.h>
#include <stdlib.h>

typedef struct 		s_win
{
	void	*mlx;
	void	*win;
}					t_win;

int		my_key_funct(int keycode, void *info)
{
	t_win *win_info;

	win_info = info;
	mlx_pixel_put(win_info->mlx, win_info->win, 300, 300, 0xff00ff);
	printf("key event %d\n", keycode);
	return (0);
}

int		main(int ac, char **av)
{
	t_win *win_info;
	(void)ac;
	(void)av;
	int	x;
	int	y;
	int pwd;

	pwd = 0;

	pwd = rand();
	ft_putnbr(pwd);

	win_info = malloc(sizeof(t_win) * 1);
	win_info->mlx = mlx_init();
	win_info->win = mlx_new_window(win_info->mlx, 2880, 1800, "42");
	x = 30;
	mlx_key_hook(win_info->win, my_key_funct, win_info->mlx);
	mlx_loop(win_info->mlx);
	return (0);
}
