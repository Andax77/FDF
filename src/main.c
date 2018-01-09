/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:20:30 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/20 12:41:58 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int ft_compare(char *line)
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
		++len;
	}
	free(tab);
	return (len);
}

t_point ft_len_file(const char *str)
{
	t_point size_map;
	char	*line;
	char 	**tab;
	int 	fd;

	printf("yolo\n");
	fd = open(str, O_RDONLY);
	size_map.x = 0;
	size_map.y = 1;
	if (get_next_line(fd, &line) != 1)
		exit(0);
		printf("yolo\n");
	if (ft_compare(line) == 0)
		exit(0);
		printf("yolo\n");
	if (!(tab = ft_strsplit(line, 32)))
		exit(0);
		printf("yolo\n");
	size_map.x = ft_splitlen(tab);
	printf("yolo\n");
  while (get_next_line(fd, &line) == 1)
	{
		printf("hhhh\n");
		size_map.y++;
		if (ft_compare(line) == 0)
			exit(0);
			printf("hhh\n");
		if (!(tab = ft_strsplit(line, 32)))
			exit(0);
			printf("hhh\n");
		if (size_map.x != ft_splitlen(tab))
			exit(0);
			printf("hhh\n");
		free(line);
	}
	free(line);
	close(fd);
	printf("yolo\n");
	return (size_map);
}

int main(int argc, const char *argv[])
{
	t_e e;
	char *line;
	int 	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	free(line);
	close(fd);
	if (!(e.mlx = mlx_init()) ||
	!(e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42")) ||
	!(e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT)) ||
	!(e.img_str = (int*)mlx_get_data_addr(e.img, &e.bpp, &e.size_l, &e.end)))
		return (0);
	e.map = ft_read(argv[1], 0, &e);
	ft_trace(e.map, &e, e.size);
	mlx_key_hook(e.win, ft_keyboard, &e);
	mlx_loop(e.mlx);
	return (0);
}
