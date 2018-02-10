#include "../includes/fdf.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

double	***scale(double ***tab, int max_x, int max_y, int max_z)
{
	int *camera_setback;

	camera_setback = NULL;
	if (!(camera_setback = (int*)malloc(sizeof(int)*3)))
		return (NULL);
	camera_setback[0] = max_x;
	camera_setback[1] = max_y;
	camera_setback[2] = max_z;
	tab = table_transform_handler(tab, CAMERA_SETBACK, camera_setback);
	return (tab);
}
