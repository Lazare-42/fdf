/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 11:41:29 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/22 11:58:41 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include "../libft/includes/libft.h"

static void	set_default_sin_cos(double **g_cos_sinus)
{
	(*g_cos_sinus)[0] = 1;
	(*g_cos_sinus)[1] = 0;
	(*g_cos_sinus)[2] = 1;
	(*g_cos_sinus)[3] = 0;
	(*g_cos_sinus)[4] = 1;
	(*g_cos_sinus)[5] = 0;
}

static void	modify_sin_cos(double **g_cos_sinus, int input_operation)
{
	double		edge;
	static int	setback[3];

	(input_operation == KEY_UP) ? setback[2]-- : 0;
	(input_operation == KEY_DOWN) ? setback[2]++ : 0;
	(input_operation == KEY_LEFT) ? setback[1]-- : 0;
	(input_operation == KEY_RIGHT) ? setback[1]++ : 0;
	edge = sqrt(setback[0] * setback[0] + setback[1] *
			setback[1] + setback[2] * setback[2]);
	if (edge)
	{
		(*g_cos_sinus)[0] = setback[0] / edge;
		(*g_cos_sinus)[1] = sqrt(1 - (*g_cos_sinus)[0] * (*g_cos_sinus)[0]);
		(*g_cos_sinus)[2] = setback[1] / edge;
		(*g_cos_sinus)[3] = sqrt(1 - (*g_cos_sinus)[2] * (*g_cos_sinus)[2]);
		(*g_cos_sinus)[4] = setback[2] / edge;
		(*g_cos_sinus)[5] = sqrt(1 - (*g_cos_sinus)[4] * (*g_cos_sinus)[4]);
	}
	else
		set_default_sin_cos(g_cos_sinus);
}

double		***camera_move(double ***tab, int input_operation,
		double **g_cos_sinus)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			tab[i][j][2] = (input_operation ==
					KEY_UP) ? tab[i][j][2]-- : tab[i][j][2];
			tab[i][j][2] = (input_operation ==
					KEY_DOWN) ? tab[i][j][2]++ : tab[i][j][2];
			tab[i][j][1] = (input_operation ==
					KEY_LEFT) ? tab[i][j][1]-- : tab[i][j][1];
			tab[i][j][1] = (input_operation ==
					KEY_RIGHT) ? tab[i][j][1]++ : tab[i][j][1];
		}
	}
	modify_sin_cos(g_cos_sinus, input_operation);
	return (tab);
}
