#include "./fdf.h"
#include "./libft/include/libft.h"

void	print_tab_debug(float ***TABTAB)
{
	int i;
	int j;

	i = 0;
	if (TABTAB)
	{
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				ft_putnbr(TABTAB[i][j][0]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				ft_putnbr(TABTAB[i][j][1]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
		i = 0;
		while(TABTAB[i])
		{
			j = 0;
			while (TABTAB[i][j])
			{
				ft_putnbr(TABTAB[i][j][2]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
}
