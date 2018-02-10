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

#include "../libft/include/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

static int g_max_z = 0;
static int g_max_y = 0;
static int g_max_x = 0;

static double		**converse_final(double **double_tab, char **tmp, int y)
{
	int				x;
	int				i;

	x = 0;
	i = -1;
	while (tmp[++i])
	{
		if (!(double_tab[i] = (double*)malloc(sizeof(double) * 3)))
			return (NULL);
		double_tab[i][0] = x;
		double_tab[i][1] = ft_atoi(tmp[i]);
		(double_tab[i][1] > g_max_y ) ? g_max_y = double_tab[i][1] : 0;
		double_tab[i][2] = y + 1;
		x++;
	}
	g_max_x = x;
	ft_memdel((void**)tmp);
	return (double_tab);
}

static double		**ft_converse_string_to_double(double **double_tab, char *line, int y_size)
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
	if (nbr != nbr_len || (!(double_tab = (double**)malloc(sizeof(double*) * (nbr_len + 1)))))
	{
		ft_putstr("Invalid argument format.\n");
		ft_memdel((void**)tmp);
		return (NULL);
	}
	double_tab[nbr_len] = NULL;
	return (converse_final(double_tab, tmp, y_size));
}

static double		***ft_parse_chartab(char **asci_tab)
{
	int			i;
	int			y_size;
	double		*tmp_char;
	double		***double_tab;

	double_tab = NULL;
	i = ft_tabsize(asci_tab);
	y_size = i - 1;
	tmp_char = NULL;
	if (!(double_tab = (double***)malloc(sizeof(double**) * (i + 1))))
		return (NULL);
	double_tab[i] = NULL;
	i = 0;
	while (asci_tab[i])
	{
		if (!(double_tab[i] = ft_converse_string_to_double(double_tab[i], asci_tab[i], y_size)))
		{
			ft_memdel((void**)double_tab);
			return (NULL);
		}
		y_size--;
		i++;
	}
	g_max_z = i;
	return (double_tab);
}

static double		***ft_parse_lines(double fd)
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
	return (ft_parse_chartab(map_asci_tab));
}

double				***ft_parsing(char *arg)
{
	double		fd;
	DIR		*test_dir;

	fd = -1;
	test_dir = NULL;
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
	return (scale(ft_parse_lines(fd), g_max_x, g_max_y, g_max_z));
}
