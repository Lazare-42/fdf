#include <stdlib.h>
#include "../libft/includes/libft.h"

double	***create_temp_tab(int	*dimensions, double ***tocopy)
{
	int		i;
	int		j;
	double	***tab;

	i = 0;
	tab = NULL;
	if (!(tab = malloc(sizeof(double**) * (dimensions[2] + 1))))
		return (NULL);
	while (i != dimensions[2] + 1)
	{
		tab[i] = NULL;
		i++;
	}
	i = 0;
	while (i < dimensions[2])
	{
		if (!(tab[i] = malloc(sizeof(double*) * (dimensions[0] + 1))))
			return (NULL);
		j = 0;
		ft_memset(tab[i], 0, dimensions[0]);
			/*
		while (j != dimensions[0] + 1)
		{
			tab[i][j] = NULL;
			j++;
		}
		*/
		j  = 0;
		while (j < dimensions[0])
		{
			if (!(tab[i][j] = malloc(sizeof(double) * 3)))
				return (NULL);
			tab[i][j][0] = tocopy[i][j][0];
			tab[i][j][1] = tocopy[i][j][1];
			tab[i][j][2] = tocopy[i][j][2];
			j++;
			debug();
		}
		i++;
	}
	return (tab);
}
