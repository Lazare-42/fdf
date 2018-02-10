#include "../includes/fdf.h"
#include "../libft/include/libft.h"
#include <stdio.h>

void	print_tab_debug(double ***tab)
{
	int i;
	int j;

	i = 0;
	ft_putchar('\n');
	if (tab)
	{
		while(tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				printf("%G\n",X);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
			ft_putchar('\n');
		while(tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				printf("%G\n",Y);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
		ft_putchar('\n');
		while(tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				printf("%G\n",Z);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
}
