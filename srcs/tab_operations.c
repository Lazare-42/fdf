/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:15:14 by lazrossi          #+#    #+#             */
/*   Updated: 2018/02/21 17:15:50 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/libft.h"

double	***create_temp_tab(int *dimensions, double ***tocopy)
{
	int		i;
	int		j;
	double	***tab;

	i = -1;
	tab = NULL;
	if (!(tab = malloc(sizeof(double**) * (dimensions[2] + 1))))
		return (NULL);
	ft_memset(tab, 0, sizeof(double**) * (dimensions[2] + 1));
	while (++i < dimensions[2])
	{
		if (!(tab[i] = malloc(sizeof(double*) * (dimensions[0] + 1))))
			return (NULL);
		ft_memset(tab[i], 0, sizeof(double*) * (dimensions[0] + 1));
		j = -1;
		while (++j < dimensions[0])
		{
			if (!(tab[i][j] = malloc(sizeof(double) * 3)))
				return (NULL);
			tab[i][j][0] = tocopy[i][j][0];
			tab[i][j][1] = tocopy[i][j][1];
			tab[i][j][2] = tocopy[i][j][2];
		}
	}
	return (tab);
}
