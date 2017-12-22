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

static int		*ft_converse_char_to_int(int *int_tab, char *line)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (!(tmp = ft_strsplit(line, ' ')))
		return (NULL);
	if (!(int_tab = malloc(sizeof(int) * ft_tabsize(tmp) + 1)))
		return (NULL);
	int_tab[ft_tabsize(tmp)] = 2147483647;
	while (tmp[i])
	{
		int_tab[i] = ft_atoi(tmp[i]);
		i++;
	}
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
			return (NULL);
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
		map_asci_tab = ft_tab_dup_add_free(map_asci_tab, tmp);
		ft_memdel((void**)&tmp);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (ft_parse_chartab(map_asci_tab));
}

int				**ft_parsing(char *arg)
{
	char	*file_path;
	int		fd;
	char	path[1024];

	fd = -1;
	file_path = NULL;
	if (!(getcwd(path, 1024)))
		return (NULL);
	if (!(file_path = ft_strjoin(path, "/")))
		return (NULL);
	if (!(file_path = ft_strjoinfree(&file_path, &arg, 'L')))
		return (NULL);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putstr("Unable to open file passed in argument\n");
		strerror(errno);
		return (NULL);
	}
	return (ft_parse_lines(fd));
}
