#include "../includes/fdf.h"
#include "../libft/include/libft.h"

float	***scale(float ***tab, int max_x, int max_y, int max_z)
{
	ft_putnbr(max_x);
	ft_putchar(' ');
	ft_putnbr(max_y);
	ft_putnbr(max_z);
	int i;
	int j;

	print_tab_debug(tab);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			//put to screen space by dividing by z
			tab[i][j][0] /= tab[i][j][2];
			tab[i][j][1] /= tab[i][j][2];

			//adapt to screen by adapting to normalized device coordinates , from 0 to 1
			tab[i][j][0] = (tab[i][j][0] + X_SIZE / 2) / X_SIZE;
			tab[i][j][1] = (tab[i][j][1] + Y_SIZE / 2) / Y_SIZE;

			//adapt to screen by adapting to raster space
			tab[i][j][0] *= X_SIZE; 
			tab[i][j][1] *= Y_SIZE;
			//	tab[i][0] /= tab[i][2];
			//	tab[i][1] /= tab[i][2];
			j++;
		}
		i++;
	}
	print_tab_debug(tab);
	(void)max_y;
	return (tab);
}
