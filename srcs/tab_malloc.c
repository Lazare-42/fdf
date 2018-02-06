#include <stdlib.h>
#include "./fdf.h"

float	***create_rotation_matrix(float ***g_rotate_matrix)
{
	int i;
	int j;
	int k;

	i = 0;
	if (!(g_rotate_matrix = (float***)malloc(sizeof(float**) * 3)))
		return (NULL);
	while (i < 3)
	{
		if (!(g_rotate_matrix[i] = (float**)malloc(sizeof(float*) * 3)))
			return (NULL);
		j = 0;
		while (j < 3)
		{
			k = -1;
			if (!(g_rotate_matrix[i][j] = (float*)malloc(sizeof(float) * 3)))
				return (NULL);
			while (++k < 3)
				g_rotate_matrix[i][j][k] = 0;
			j++;
		}
		i++;
	}
	return (g_rotate_matrix);
}
