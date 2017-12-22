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
    int     wtf2;
    int     wtf3;
    int     go;

    go = 0;
    wtf3 = 1;
    line.x2 = 350;
    line.x1 = 350;
    line.y2 = 250;
    line.y1 = 450;

    line.x1 > line.x2 ? ft_swap(&line.x1, &line.x2),
     ft_swap(&line.y1, &line.y2) : 1;
    x = line.x1;
    line.dx = line.x2 - line.x1;
    line.dy = line.y2 - line.y1;
    line.dy > 0 ? wtf3 = -1 : 1;
    printf("%d\n",line.dy);
    printf("%d\n",line.dx);
    abs(line.dy) < line.dx ? go = 1 : 1;
    line.dx == 0 ? line.dx = 1 : 1;
    while (x <= line.x2 && go == 0)
    {
      wtf2 = 0;
      wtf = (line.dy * (x - line.x1) / line.dx);
      printf("%d\n",wtf);
      printf("%d\n", line.dy * (x + 1 - line.x1 / line.dx) + wtf2);
      while (wtf != (line.dy * (x + 1 - line.x1) / line.dx) + wtf2)
      {
        i = (WIN_HEIGHT - line.y1 - wtf2) * WIN_WIDTH + x - wtf * WIN_WIDTH;
        printf("COUCOU\n");
        if (i >= 0 && i < WIN_WIDTH * WIN_HEIGHT)
        image[i] = color;
        wtf2 = wtf2 + wtf3;
      }
      x++;
    }
    while (x <= line.x2 && go == 1)
    {
      printf("CAPASSE\n");
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
