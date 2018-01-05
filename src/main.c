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

t_point ft_len_file(int fd)
{
	t_point size_map;
	char	*line;
	char 	**tab;

	size_map.x = 0;
	size_map.y = 1;
	if (get_next_line(fd, &line) != 1)
		exit(0);
	printf("\nfd:%d %s\n", fd,line);
	if (ft_compare(line) == 0)
		exit(0);
	if (!(tab = ft_strsplit(line, 32)))
		exit(0);
	size_map.x = ft_splitlen(tab);
  while (get_next_line(fd, &line) == 1)
	{
		size_map.y++;
		if (ft_compare(line) == 0)
			exit(0);
		if (!(tab = ft_strsplit(line, 32)))
			exit(0);
		if (size_map.x != ft_splitlen(tab))
			exit(0);
		free(line);
	}
	return (size_map);
}

int main(int argc, const char *argv[])
{
	int 	**map;
	t_e e;

	map = ft_read(argv[1]);
	printf("%d%s",argc, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
  e.img_str = (int*)mlx_get_data_addr(e.img, &e.bpp, &e.size_l, &e.end);
	mlx_key_hook(e.win, ft_keyboard, &e);
	mlx_loop(e.mlx);
	return (0);
}
