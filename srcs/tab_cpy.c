#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/include/libft.h"

double	***tab_copy(double ***to_cpy, int *dimensions)
{
	int i;
	int j;
	double ***tab;

	i = 0;
	tab = NULL;
	if (!(tab = (double***)malloc(sizeof(double**) * (dimensions[2] + 1))))
		return (NULL);
	tab[dimensions[2]] = NULL;
	while (i < dimensions[2])
	{
		if (!(tab[i] = (double**)malloc(sizeof(double*) * (dimensions[0] + 1))))
			return (NULL);
		tab[dimensions[0]] = NULL;
		i++;
	}
	i = 0;
	while (to_cpy[i])
	{
		j = 0;
		while (to_cpy[i][j])
		{
			if (!(tab[i][j] = (double*)malloc(sizeof(double) * 3)))
				return (NULL);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (to_cpy[i])
	{
		j = 0;
		while (to_cpy[i][j])
		{
			X = to_cpy[i][j][0];
			Y = to_cpy[i][j][1];
			Z = to_cpy[i][j][2];
			j++;
		}
		i++;
	}
	debug();
	print_tab_debug(tab);
	return (tab);
}
