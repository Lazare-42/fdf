/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:39:09 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/22 13:40:43 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/include/libft.h"

int		main(int ac, char **av)
{
	(void)ac;

	float	***tab;
	tab = NULL;

	int i;
	int j;
	int k;

	i = 0;
	k = 0;

	if (av[1])
		tab = ft_parsing(av[1]);
	else 
		ft_putstr("Pass a file to FDF to launch the program\n");
	if (tab)
	{
		while(tab[i])
		{
			j = 0;
			while (tab[i][j])
			{
				ft_putnbr(tab[i][j][2]);
				ft_putchar(' ');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
	return (0);
}
