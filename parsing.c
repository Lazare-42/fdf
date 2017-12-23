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

#include "./libft/include/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

static int		*ft_converse_char_to_int(int *int_tab, char *line)
{
	char		**tmp;
	static int	nbr = 0;
	int			i;
	int			nbr_len;

	tmp = NULL;
	i = -1;
	nbr_len = 0;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (NULL);
	nbr_len = ft_tabsize(tmp);
	if (!nbr)
		nbr = nbr_len;
	if (nbr != nbr_len || (!(int_tab = malloc(sizeof(int) * nbr_len + 1))))
	{
		ft_memdel((void**)tmp);
		return (NULL);
	}
	int_tab[nbr_len] = 2147483647;
	while (tmp[++i])
		int_tab[i] = ft_atoi(tmp[i]);
	ft_memdel((void**)tmp);
	return (int_tab);
}

static int		**ft_parse_chartab(char **asci_tab)
{
	int		i;
	int		*tmp_char;
	int		**int_tab;

	int_tab = NULL;
	i = ft_tabsize(asci_tab);
	tmp_char = NULL;
	if (!(int_tab = (int**)malloc(sizeof(int*) * (i + 1))))
		return (NULL);
	int_tab[i] = NULL;
	i = 0;
	while (asci_tab[i])
	{
		if (!(int_tab[i] = ft_converse_char_to_int(int_tab[i], asci_tab[i])))
		{
			ft_memdel((void**)int_tab);
			return (NULL);
		}
		i++;
	}
	return (int_tab);
}

static int		**ft_parse_lines(int fd)
{
	char	*tmp;
	char	**map_asci_tab;
	int		ret;

	tmp = NULL;
	map_asci_tab = NULL;
	ret = 0;
	if (!(map_asci_tab = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	map_asci_tab[0] = NULL;
	while ((ret = get_next_line(fd, &tmp, '\n')) && ret != -1)
	{
		if (!(map_asci_tab = ft_tab_dup_add_free(map_asci_tab, tmp)))
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

int				**ft_parsing(char *arg)
{
	int		fd;
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
	return (ft_parse_lines(fd));
}

int		main(int ac, char **argv)
{
	(void)ac;
	int **tmp_tab;

	tmp_tab = NULL;
	tmp_tab = ft_parsing(argv[1]);
	int x;
	int y;
	x = 0;
	while (tmp_tab && tmp_tab[x])
	{
		y = 0;
		while (tmp_tab[x][y] != 2147483647)
		{
			ft_putnbr(tmp_tab[x][y]);
			ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	return (0);
}
