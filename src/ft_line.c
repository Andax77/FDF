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
		printf("COUCUO\n");
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
			i = (WIN_HEIGHT - ln->y1 - wtf->wtf2)
				* WIN_WIDTH + x - wtf->wtf * WIN_WIDTH;
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
	line.dx == 0 ? ft_unexpected(image, color, &line, &wtf.go) : 1;
	ft_while(&line, &wtf, image, color);
}

/*void ft_fill_image(int *image, int color)
{
  int i;
  int segment;
  int MINUS;
  int LINE_MINUS;
  int MARGIN;

  MINUS = WIN_WIDTH > WIN_HEIGHT ? WIN_WIDTH : WIN_HEIGHT;
  printf("MINUS :%d\n", MINUS);
  LINE_MINUS = WIN_WIDTH > WIN_HEIGHT ? 19 : 10;
  printf("LINE_MINUS :%d\n", LINE_MINUS);
  MARGIN = 0.1 * MINUS;
  printf("MARGIN :%d\n", MARGIN);
  segment = (MINUS - 2 * MARGIN) / LINE_MINUS;
  printf("seegment :%d\n", segment);
  i = WIN_WIDTH * MARGIN + MARGIN;
  printf("Number :%d\n", i);
  while (i < ((WIN_WIDTH * WIN_HEIGHT) - MARGIN - (WIN_WIDTH * MARGIN)))
  {
    image[i++] = color;
    if ((i + MARGIN) % WIN_WIDTH == 0)
    {
      printf("Number :%d\n", i);
      i +=  WIN_WIDTH * (segment - 1) + MARGIN * 2;
    }
  }
}
*/
