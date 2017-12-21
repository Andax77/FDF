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

void ft_fill_image(int *image, int color)//ft_line
{
    t_line  line;
    int     x;
    int     i;
    int     wtf;

    line.x2 = 150;
    line.x1 = 150;
    line.y2 = 750;
    line.y1 = 250;

    line.x1 > line.x2 ? ft_swap(&line.x1, &line.x2),
     ft_swap(&line.y1, &line.y2) : 1;
    x = line.x1;
    line.dx = line.x2 - line.x1;
    line.dy = line.y2 - line.y1;
    line.dx == 0 ? line.dx = 1 : 1;
    while (x <= line.x2)
    {
      wtf = (line.dy * (x - line.x1) / line.dx);
      i = (WIN_HEIGHT - line.y1) * WIN_WIDTH + x - wtf * WIN_WIDTH;
      image[i] = color;
      x++;
    }
    while (x <= line.x2)
    {
      wtf = (line.dy * (x - line.x1) / line.dx);
      i = (WIN_HEIGHT - line.y1) * WIN_WIDTH + x + wtf * WIN_WIDTH;
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
/*void  fill_image(int *image, int color)
{
  int i;

  i = WIN_WIDTH * MARGIN + MARGIN;
  while (i < WIN_WIDTH * WIN_HEIGHT - MARGIN - WIN_HEIGHT * MARGIN)
  {
    image[i] = color;
    ++i;
    if ((i + MARGIN) % WIN_WIDTH == 0)
      i += MARGIN * 2;

  }
}*/
