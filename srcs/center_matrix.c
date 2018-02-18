#include "../includes/fdf.h"

double	***center_matrix(double ***tab, int *field_size)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			tab[i][j][0] -= (field_size[0] - 1) / 2;
			tab[i][j][1] -= field_size[2] / 2;
			j++;
		}
		i++;
	}
	return (tab = table_transform_handler(tab, CAMERA_SETBACK));
}
