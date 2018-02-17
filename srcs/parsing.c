/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:52:46 by lazrossi          #+#    #+#             */
/*   Updated: 2017/12/22 17:00:00 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

static double		**converse_final(double **tab, char **tmp, int y, int **dimensions)
{
	int				x;
	int				i;

	x = 0;
	i = -1;
	while (tmp[++i])
	{
		if (!(tab[i] = (double*)malloc(sizeof(double) * 3)))
			return (NULL);
		tab[i][0] = x;
		tab[i][1] = ft_atoi(tmp[i]);
		(tab[i][1] > (*dimensions)[1]) ? (*dimensions)[1] = tab[i][1] : 0;
		tab[i][2] = y;
		x++;
	}
	(*dimensions)[0] = x;
	ft_tabdel((void**)tmp);
	return (tab);
}

static double		**ft_converse_string_to_double(double **tab, char *line, int y_size, int **dimensions)
{
	char			**tmp;
	static double	nbr = 0;
	int				nbr_len;

	tmp = NULL;
	nbr_len = 0;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (NULL);
	nbr_len = ft_tabsize(tmp);
	if (!nbr)
		nbr = nbr_len;
	if (nbr != nbr_len || (!(tab = (double**)malloc(sizeof(double*) * (nbr_len + 1)))))
	{
		ft_putstr("Invalid argument format.\n");
		ft_tabdel((void**)tmp);
		return (NULL);
	}
	tab[nbr_len] = NULL;
	return (converse_final(tab, tmp, y_size, dimensions));
}

static double		***ft_parse_chartab(char **asci_tab, int **dimensions)
{
	int			i;
	int			y_size;
	double		***tab;

	tab = NULL;
	i = ft_tabsize(asci_tab);
	y_size = i - 1;
	if (!(tab = (double***)malloc(sizeof(double**) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	i = 0;
	(*dimensions)[1] = 0;
	while (asci_tab[i])
	{
		if (!(tab[i] = ft_converse_string_to_double(tab[i], asci_tab[i], y_size, dimensions)))
		{
			ft_memdel((void**)tab);
			// Modify this memdel to really delete
			return (NULL);
		}
		y_size--;
		i++;
	}
	(*dimensions)[2] = i;
	ft_tabdel((void**)asci_tab);
	return (tab = table_transform_handler(tab, CAMERA_SETBACK, *dimensions));
}

static double		***ft_parse_lines(double fd, int **dimensions)
{
	char	*tmp;
	char	**map_asci_tab;
	double		ret;

	tmp = NULL;
	map_asci_tab = NULL;
	ret = 0;
	if (!(map_asci_tab = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	map_asci_tab[0] = NULL;
	while ((ret = get_next_line(fd, &tmp, '\n')) && ret != -1)
	{
		if (!(map_asci_tab = ft_tabdup_and_add(map_asci_tab, tmp)))
		{
			ft_memdel((void**)&map_asci_tab);
			ft_memdel((void**)&tmp);
		}
		ft_memdel((void**)&tmp);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (ft_parse_chartab(map_asci_tab, dimensions));
}

double				***ft_parsing(char *arg, int **dimensions)
{
	double		fd;
	DIR		*test_dir;

	fd = -1;
	test_dir = NULL;
	if (!(*dimensions = (int*)malloc(sizeof(int) * 3)))
		return (NULL);
	if ((test_dir = opendir(arg)))
	{
		ft_putstr("Pass a file not a directory to fdf.\n");
		return (NULL);
	}
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putstr("Unable to open file passed in argument.\n");
		strerror(errno);
		return (NULL);
	}
	return (ft_parse_lines(fd, dimensions));
}
