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


int		main(int ac, char **av)
{
	(void)ac;

	long ***tab;

	tab = NULL;
	if (av[1])
		tab = ft_parsing(av[1])
	else 
		ft_putstr("Pass a file to FDF to launch the program\n");
	return (0);
}
