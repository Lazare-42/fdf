#include "../includes/fdf.h"
#include "../libft/include/libft.h"

void	draw_line(float *from, float *to, int **screen)
{
	float dx;
	float dy;
	float D;
	float y;
	int x;

	dx = from[0] - to[0];
	dy = from[1] - to[1];
	x = from[0];
	y = from[1];
	D = 2 * dy - dx;
	while (x < to[0])
	{
		(*screen)[(int)x + (int)y * X_SIZE] = 0xFEFFFF;
		if (D > 0)
		{
			y++;
			D -= 2 * dx;
		}
		D *= 2 * dy;
	}

}

void put_to_screen_string(float *tab, int **screen)
{
	(*screen)[(int)tab[0] + (int)tab[1] * X_SIZE] = 0xFEFFFF;
}
