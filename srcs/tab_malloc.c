#include <stdlib.h>
#include "./fdf.h"

double	***create_rotation_matrix(double ***g_rotate_matrix)
{
	int i;
	int j;
	int k;

	i = 0;
	if (!(g_rotate_matrix = (double***)malloc(sizeof(double**) * 3)))
		return (NULL);
	while (i < 3)
	{
		if (!(g_rotate_matrix[i] = (double**)malloc(sizeof(double*) * 3)))
			return (NULL);
		j = 0;
		while (j < 3)
		{
			k = -1;
			if (!(g_rotate_matrix[i][j] = (double*)malloc(sizeof(double) * 3)))
				return (NULL);
			while (++k < 3)
				g_rotate_matrix[i][j][k] = 0;
			j++;
		}
		i++;
	}
	return (g_rotate_matrix);
}
