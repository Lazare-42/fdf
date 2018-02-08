#include "../includes/fdf.h"
#include <stdio.h>
#include "../libft/include/libft.h"

void	print_tab_debug(double ***TABTAB)
{
	int i;
	int j;

	i = 0;
	ft_putchar('\n');
	if (TABTAB)
	{
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				printf("%G ", TABTAB[i][j][0]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
			ft_putchar('\n');
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				printf("%d ", (int)TABTAB[i][j][1]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
		ft_putchar('\n');
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				printf("%G ", TABTAB[i][j][2]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
}
