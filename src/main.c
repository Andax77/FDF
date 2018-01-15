/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:20:30 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/12 18:10:19 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_compare(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit((int)line[i]) == 0 && line[i] != 32 && line[i] != '-' &&
			line[i] != '\t' && line[i] != '\r')
			return (0);
		++i;
	}
	return (1);
}

int		ft_splitlen(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
	{
		free(tab[len]);
		len++;
	}
	free(tab);
	return (len);
}

t_point	ft_len_file(const char *str)
{
	t_point size_map;
	char	*line;
	char	**tab;
	int		fd;

	if (!(fd = open(str, O_RDONLY)))
		ft_error("Opening File Failed.\n");
	size_map.x = 0;
	size_map.y = 1;
	if (get_next_line(fd, &line) != 1)
		ft_error("Error GNL -> main.c.\n");
	if (ft_compare(line) == 0)
		ft_error("You should have only digit -> main.c.\n");
	if (!(tab = ft_strsplit(line, 32)))
		ft_error("Split Failed -> main.c.\n");
	size_map.x = ft_splitlen(tab);
	ft_len_file2(&size_map, tab, line, fd);
	close(fd);
	free(line);
	return (size_map);
}

void	init_var(t_e *e)
{
	e->offset.x = 400;
	e->offset.y = 200;
	e->clr = 0xFFFFFF;
	e->zoom = WIN_WIDTH / (3 * e->size.x);
	e->z = -e->zoom;
}

int		main(int argc, const char *argv[])
{
	t_e		e;

	if (argc != 2)
		ft_error("There is more or less of 1 file -> main.c\n");
	if (!(e.mlx = mlx_init()) ||
	!(e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42")) ||
	!(e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT)) ||
	!(e.img_str = (int*)mlx_get_data_addr(e.img, &e.bpp, &e.size_l, &e.end)))
		ft_error("mlx get rekt -> main.c.\n");
	e.map = ft_read(argv[1], 0, &e);
	init_var(&e);
	ft_trace(e.map, &e, e.size);
	mlx_key_hook(e.win, ft_keyboard, &e);
	mlx_loop(e.mlx);
	return (0);
}
