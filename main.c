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
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <term.h>

int	set_non_canonical_input(void)
{
	struct termios termios_cpy;

	if (tcgetattr(0, &termios_cpy) != 0)
		return (0);
	termios_cpy.c_cc[VMIN] = 1;
	termios_cpy.c_cc[VTIME] = 0;
	termios_cpy.c_lflag &= (IGNBRK);
	termios_cpy.c_lflag &= (ICANON);
	if (tcsetattr(0, TCSANOW, &termios_cpy) != 0)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	(void)ac;

	int i;
	int j;
	int k;
	float ***TABTAB;
	TABTAB = NULL;

	i = 0;
	k = 0;
	if (!(set_non_canonical_input()))
		return (0);

	if (av[1])
		TABTAB = ft_parsing(av[1]);
	else 
		ft_putstr("Pass a file to FDF to launch the program\n");
	if (TABTAB)
	{
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
	float sinus;
	float cosinus;
	float angle;
	int ret;
	char buf;
	ret = 1;
	cosinus = 0;
	sinus = 0;
	angle = 1;
	while ((ret = read(1, &buf, 4)))
	{
		if (buf == 'p')
		angle += 0.001;
		else 
			angle -= 0.001;
		sinus = sin(angle);
		cosinus = 1 - sinus * sinus;
		cosinus = sqrt(cosinus);
		printf("%G\n", sinus);
		printf("%G\n", cosinus);
	}
	return (0);
}
