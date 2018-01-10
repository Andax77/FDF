/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:08:48 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/04 15:14:40 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_unexpected(int *image, int color, t_line *line, int *go2)
{
	int		i;
	int		y;
	int		go;

	*go2 = 3;
	go = line->y1;
	y = -1;
	line->y1 > line->y2 ? go = line->y2 : 0;
	line->y1 > line->y2 ? y = 1 : 0;
	i = (WIN_HEIGHT - go) * WIN_WIDTH + line->x1;
	if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
		image[i] = color;
	while (line->y1 != line->y2)
	{
		i -= WIN_WIDTH;
		if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
			image[i] = color;
		line->y2 += y;
	}
}

void	ft_while(t_line *ln, t_wtf *wtf, int *image, int color)
{
	int		i;
	int		x;

	x = ln->x1;
	while (x <= ln->x2 && wtf->go == 0)
	{
		wtf->wtf2 = 0;
		wtf->wtf = (ln->dy * (x - ln->x1) / ln->dx);
		while (wtf->wtf != (ln->dy * (x + 1 - ln->x1) / ln->dx) + wtf->wtf2)
		{
			i = (WIN_HEIGHT - ln->y1 - wtf->wtf)
				* WIN_WIDTH + x - wtf->wtf2 * WIN_WIDTH;
			if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
				image[i] = color;
			wtf->wtf2 += wtf->wtf3;
		}
		x++;
	}
	while (x <= ln->x2 && wtf->go == 1)
	{
		wtf->wtf = (ln->dy * (x - ln->x1) / ln->dx);
		i = (WIN_HEIGHT - ln->y1) * WIN_WIDTH + x - wtf->wtf * WIN_WIDTH;
		// printf("(%d)\n",i);
		if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
			image[i] = color;
		x++;
	}
}

void	ft_double_swap(t_line *line)
{
	ft_swap(&line->x1, &line->x2);
	ft_swap(&line->y1, &line->y2);
}

void	ft_line(int *image, int color, t_point pt1, t_point pt2)
{
	t_line	line;
	t_wtf	wtf;

	// if (pt1.x < 0 || pt2.x < 0 || pt1.x > WIN_WIDTH || pt2.x > WIN_WIDTH)
		// return ;
	wtf.wtf3 = 1;
	wtf.go = 0;
	line.x2 = pt2.x;
	line.x1 = pt1.x;
	line.y2 = pt2.y;
	line.y1 = pt1.y;
	line.x1 > line.x2 ? ft_double_swap(&line) : 1;
	line.dx = line.x2 - line.x1;
	line.dy = line.y2 - line.y1;
	line.dy > 0 ? wtf.wtf3 = -1 : 1;
	abs(line.dy) < line.dx ? wtf.go = 1 : 1;
	while (line.x1 < 0)
		line.x1++;
	while (line.x1 > WIN_WIDTH)
		line.x1--;
	line.dx == 0 ? ft_unexpected(image, color, &line, &wtf.go) : 1;
	ft_while(&line, &wtf, image, color);
}
