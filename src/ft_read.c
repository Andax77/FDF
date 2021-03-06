/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:22:28 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/08 14:14:46 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_fill_map(int *map, char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		map[i] = ft_atoi(tab[i]);
		++i;
	}
}

void	ft_bigger(int *fd, const char *file, t_point *size_map, int ***map)
{
	if (!(*fd = open(file, O_RDONLY)))
		ft_error("Opening File Failed.\n");
	*size_map = ft_len_file(file);
	close(*fd);
	if (!(*fd = open(file, O_RDONLY)))
		ft_error("Opening File Failed.\n");
	if (!(*map = (int**)malloc(sizeof(*map) * size_map->y)))
		ft_error("Allocation Failed.\n");
}

int		**ft_read(const char *file, int fd, t_e *e)
{
	t_point		size_map;
	char		*line;
	char		**tab;
	int			**map;
	int			i;

	map = NULL;
	ft_bigger(&fd, file, &size_map, &map);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(map[i] = (int*)malloc(sizeof(int) * size_map.x)))
			return (NULL);
		if (!(tab = ft_strsplit(line, 32)))
			return (NULL);
		ft_fill_map(map[i++], tab);
		ft_splitlen(tab);
		free(line);
	}
	free(line);
	close(fd);
	e->size = size_map;
	return (map);
}
