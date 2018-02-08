#include "../includes/fdf.h"
#include "../libft/include/libft.h"


double	***scale(double ***tab, int max_x, int max_y, int max_z)
{
	int i;
	int j;
	int scale_x;
	int scale_y;
	int scale_z;
	int	screen_adjust_x;
	int	screen_adjust_y;

	i = -1;
	scale_x = X_SIZE / max_x;
	scale_y = Y_SIZE  / max_y;
	scale_z = Y_SIZE / 6 / max_y;
	screen_adjust_x = X_SIZE / 4;
	screen_adjust_y = Y_SIZE / 4;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if ((i + 1) <= max_z / 2 && (1 + j) <= max_x / 2)
			{
				tab[i][j][2] = tab[-1 + max_z - i ][-1 + max_x - j][2];
			}
//			tab[i][j][0] *= scale_x;
//			tab[i][j][0] += screen_adjust_x;
//			tab[i][j][1] *= scale_y;
//			tab[i][j][1] += screen_adjust_y;
		}
	}
	return (tab);
}
