/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:19:23 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 12:24:55 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>

static int		*set_var_lines(double *from, double *to, double **point)
{
	int		*op;

	op = NULL;
	(*point) = set_get_pixel(NULL);
	(*point)[0] = (int)from[0];
	(*point)[1] = (int)from[1];
	if (!(op = malloc(sizeof(int) * 6)))
		ft_myexit("malloc error");
	op[0] = (int)(to[0] - from[0]);
	op[1] = (int)(to[1] - from[1]);
	op[3] = (op[0] > 0) ? 1 : -1;
	op[4] = (op[1] > 0) ? 1 : -1;
	op[0] = abs(op[0]);
	op[1] = abs(op[1]);
	op[2] = 0;
	return (op);
}

static void		set_high(int *op, double *point, int **screen, int print)
{
	op[5] = op[0] / 2;
	while (++op[2] <= op[0])
	{
		point[0] += op[3];
		op[5] += op[1];
		if (op[5] >= op[0])
		{
			op[5] -= op[0];
			point[1] += op[4];
		}
		put_screen_str(screen, print);
	}
}

void			draw_line(double *from, double *to, int **screen, int print)
{
	int		*op;
	double	*point;

	op = set_var_lines(from, to, &point);
	put_screen_str(screen, print);
	(op[0] > op[1]) ? set_high(op, point, screen, print) : 0;
	if (op[0] <= op[1])
	{
		op[5] = op[1] / 2;
		while (++op[2] <= op[1])
		{
			point[1] += op[4];
			op[5] += op[0];
			if (op[5] >= op[1])
			{
				op[5] -= op[1];
				point[0] += op[3];
			}
			put_screen_str(screen, print);
		}
	}
	ft_memdel((void**)&op);
	set_get_pixel(point);
}
