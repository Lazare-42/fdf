#include "../includes/fdf.h"
#include "../libft/include/libft.h"

float	***scale(float ***tab, int max_x, int max_y, int max_z)
{
	print_tab_debug(tab);
	int i;
	int j;
	
	i = 0;
	ft_putnbr(max_x);
	ft_putchar(' ');
	ft_putnbr(max_y);
	ft_putchar(' ');
	ft_putchar('\n');

	while (tab[i])
	{
		int first;
		j = 0;
		first = 1;
		while (tab[i][j])
		{
			if (first)
			{
				ft_putnbr(tab[i][j][2]);
				ft_putchar('\n');
			}
			first = 0;
			tab[i][j][0] *= (X_SIZE / 3 ) / max_x;
			tab[i][j][0] += X_SIZE / 3;
			tab[i][j][2] *= (Y_SIZE / 3) / max_z;
			tab[i][j][2] += Y_SIZE / 3;
			j++;
		}
		i++;
	}
	(void)max_y;
	return (tab);
}
