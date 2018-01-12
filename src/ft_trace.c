/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:22:09 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/12 16:23:59 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	ft_clear_img(int *img)
{
	int		i;

	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
		img[i++] = 0;
}

void	ft_trace_line(t_point **tab, int height, int width, t_e *e)
{
	int		x;
	int		y;

	y = 0;
	ft_clear_img(e->img_str);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x + 1 < width)
			{
				ft_line(tab[y][x], tab[y][x + 1], e);
			}
			if (y + 1 < height)
			{
				ft_line(tab[y][x], tab[y + 1][x], e);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	ft_leak(t_point **new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free(new);
}

void	ft_trace(int **old, t_e *e, t_point size)
{
	t_point		pt;
	t_point		**new;

	if (!(new = (t_point**)malloc(sizeof(t_point*) * (size.y + 1))))
		ft_error("Allocation Failed ft_trace.c.\n");
	pt.y = 0;
	while (pt.y < size.y)
	{
		if (!(new[pt.y] = (t_point*)malloc(sizeof(t_point) * size.x)))
			ft_error("Malloc map failed ft_trace.c.\n");
		pt.x = 0;
		while (pt.x < size.x)
		{
			new[pt.y][pt.x].x = 2 * (pt.x - pt.y) * e->zoom + e->offset.x;
			new[pt.y][pt.x].y = (pt.x + pt.y) * e->zoom + e->offset.y;
			new[pt.y][pt.x].y += old[pt.y][pt.x] * e->z / 3 + 100;
			++pt.x;
		}
		++pt.y;
	}
	new[pt.y] = NULL;
	ft_trace_line(new, size.y, size.x, e);
	ft_leak(new);
}
