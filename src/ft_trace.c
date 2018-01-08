/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:22:09 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/08 14:22:11 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_trace_line(t_point **tab, int height, int width, int* img)
{
  int   x;
  int   y;

  y = 0;
  while (y - 1 != height)
  {
    x = 0;
    while (x - 1 != width)
    {
      printf("HEHE\n");
      if (y <= height && y >= 0 && x >= 0 && x <= width &&
              y + 1 <= height && y + 1 >= 0 && x >= 0 && x <= width)
              ft_line(img, 0xFFFFFF, tab[x][y], tab[y + 1][x]);
      if (y <= height && y >= 0 && x >= 0 && x <= width &&
              y <= height && y >= 0 && x + 1 >= 0 && x + 1 <= width)
              ft_line(img, 0xFFFFFF, tab[x][y], tab[y][x + 1]);
      x++;
    }
    y++;
  }
}

void    ft_trace(int **old, int *img, t_point size)
{
  t_point pt;
  t_point **new;
  int     width;
  int     height;

  height = size.x - 1;
  width = size.y - 1;
  printf("NOMBre :%d\n", width);
  if (!(new = (t_point**)malloc(sizeof(new) * height)))
    exit(0);
  pt.y = height;
  printf("HEHE1111\n");
  while (pt.y != 0)
  {
    if (!(new[height - pt.y] = (t_point*)malloc(sizeof(t_point*) * width)))
      exit(0);
    pt.x = 0;
    printf("123456\n");
    while (pt.x != width)
    {
      size.x = pt.x;
      size.y = pt.y;
      size.z = old[pt.y][pt.x];
      new[height - pt.y][pt.x] = size;
      pt.x++;
    }
    pt.y--;
    printf("PAS MAL\n");
  }
  printf("CA PASSE !\n");
  ft_trace_line(new, height, width, img);
}
