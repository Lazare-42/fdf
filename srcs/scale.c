#include "../includes/fdf.h"
#include "../libft/include/libft.h"

float	***scale(float ***tab, int max_x, int max_y, int max_z)
{
	ft_putnbr(max_x);
	ft_putnbr(max_y);
	(void)max_z;
	int	i;
	int	j;
	float scale_x;
	float scale_y;
	float scale_z;
	float	screen_adjust_x;
	float	screen_adjust_y;

	i = -1;
	scale_x = (X_SIZE / 4) / max_x;
	scale_y = (Y_SIZE  / 4) / max_y;

	scale_z = Y_SIZE / 6 / max_y;

	screen_adjust_x = X_SIZE / 4;
	screen_adjust_y = Y_SIZE / 4;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			tab[i][j][0] *= scale_x;
			tab[i][j][0] += screen_adjust_x;
			tab[i][j][1] *= scale_y;
			tab[i][j][1] += screen_adjust_y;
		}
	}
	return (tab);
}
