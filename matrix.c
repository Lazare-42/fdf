#include "fdf.h"

float	*matrix_multiplication(float *start, float **translation)
{
	start[0] = translation[0][0] * start[0] + translation[0][1] * start[1] + translation[0][2] * start[2];
	start[1] = translation[1][0] * start[0] + translation[1][1] * start[1] + translation[1][2] * start[2];
	start[2] = translation[2][0] * start[0] + translation[2][1] * start[1] + translation[2][2] * start[2];
	return (start);
}

float	**table_transform(float **start, float **translation, float *camera_pos)
{
	int i;

	i = 0;
	while (start[i])
	{
		start[i][0] -= camera_pos[0];
		start[i][0] -= camera_pos[1];
		start[i][0] -= camera_pos[2];
		start[i] = matrix_multiplication(start[i], translation);
		i++;
	}
	return (start);
}
