/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:48:30 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 12:51:05 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	set_get_zoom_x(int zoom)
{
	static double	zoom_x = 0;
	static double	zoom_factor = 1;
	static double	screen_adjust = (X_SIZE / 3);

	if (!zoom_x)
		zoom_x = screen_adjust;
	if (zoom)
	{
		zoom_factor += (zoom < 0) ? -0.02 : +0.02;
		zoom_x = screen_adjust * zoom_factor;
	}
	return (zoom_x);
}

double	set_get_zoom_y(int zoom)
{
	static double	zoom_y = 0;
	static double	zoom_factor = 1;
	static double	screen_adjust = (Y_SIZE / 3);

	if (!zoom_y)
		zoom_y = screen_adjust;
	if (zoom)
	{
		zoom_factor += (zoom < 0) ? -0.02 : +0.02;
		zoom_y = screen_adjust * zoom_factor;
	}
	return (zoom_y);
}

void	zoom_handler(int input_operation)
{
	if (input_operation == ZOOM_IN)
	{
		set_get_zoom_x(-1);
		set_get_zoom_y(-1);
		return ;
	}
	set_get_zoom_x(1);
	set_get_zoom_y(1);
}
