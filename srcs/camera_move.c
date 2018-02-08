#include "fdf.h"
#include "../libft/include/libft.h"

double	***camera_move(double ***tab, int input_operation)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			tab[i][j][2] = (input_operation == KEY_UP) ? tab[i][j][2]++ : tab[i][j][2];
			tab[i][j][2] = (input_operation == KEY_DOWN) ? tab[i][j][2]-- : tab[i][j][2];
			tab[i][j][1] = (input_operation == KEY_LEFT) ? tab[i][j][1]++ : tab[i][j][1];
			tab[i][j][1] = (input_operation == KEY_LEFT) ? tab[i][j][1]-- : tab[i][j][1];
			j++;
		}
		i++;
	}
	return (tab);
}

double	***first_camera_move(double ***tab, int max_x, int max_y, int max_z)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while(tab[++j])
		{
			debug();
			tab[0] += max_x * 4;
			tab[1] += max_y * 4;
			tab[2] += max_z * 4;
		}
	}
	return (tab);
}
