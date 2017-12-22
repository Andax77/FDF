/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:08:48 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/19 17:08:53 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
}
void ft_unexpected(int *image, int color, t_line *line)
{
  int i;
  int y;
  int go;

  go = line->y1;
  y = -1;
  line->y1 > line->y2 ? go = line->y2 : 0;
  line->y1 > line->y2 ? y = 1 : 0;
  i = (WIN_HEIGHT - go) * WIN_WIDTH + line->x1;
  image[i] = color;
  while (line->y1 != line->y2)
  {
    i -= WIN_WIDTH;
    image[i] = color;
    line->y2 += y;
  }
}

void ft_fill_image(int *image, int color)//ft_line
{
    t_line  line;
    int     x;
    int     i;
    int     wtf;
    int     wtf2;
    int     wtf3;
    int     go;

    go = 0;
    wtf3 = 1;


    line.x2 = x2;
    line.x1 = x1;
    line.y2 = y2;
    line.y1 = y1;

    line.x1 > line.x2 ? ft_swap(&line.x1, &line.x2),
     ft_swap(&line.y1, &line.y2) : 1;
    x = line.x1;
    line.dx = line.x2 - line.x1;
    line.dy = line.y2 - line.y1;
    line.dy > 0 ? wtf3 = -1 : 1;
    abs(line.dy) < line.dx ? go = 1 : 1;
    line.dx == 0 ? ft_unexpected(image, color, &line), go = 3 : 1;
    while (x <= line.x2 && go == 0)
    {
      wtf2 = 0;
      wtf = (line.dy * (x - line.x1) / line.dx);
      while (wtf != (line.dy * (x + 1 - line.x1) / line.dx) + wtf2)
      {
        i = (WIN_HEIGHT - line.y1 - wtf2) * WIN_WIDTH + x - wtf * WIN_WIDTH;
        if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
        image[i] = color;
        wtf2 += wtf3;
      }
      x++;
    }
    while (x <= line.x2 && go == 1)
    {
      wtf = (line.dy * (x - line.x1) / line.dx);
      i = (WIN_HEIGHT - line.y1) * WIN_WIDTH + x - wtf * WIN_WIDTH;
      image[i] = color;
      x++;
    }
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
