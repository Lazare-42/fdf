#include "../includes/fdf.h"
#include "../libft/include/libft.h"


int put_to_screen_string(float *tab, int **screen)
{
	static int l = 30;
	ft_putnbr(tab[0]);
	ft_putchar(' ');
	ft_putnbr(tab[1]);
	ft_putchar(' ');
	ft_putchar('\n');

	(*screen)[(int)tab[0] + (int)tab[1] * X_SIZE] = 0xFFFFFF;
	l++;
	return (0);
}
