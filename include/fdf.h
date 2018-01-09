/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:59 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/19 10:49:25 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000

#include "../libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_point
{
	int 					x;
	int 					y;
	int 					z;
}				       t_point;

typedef struct s_e
{
	void	*win;
	void	*mlx;
	void	*img;
	int   *img_str;
	int   bpp;
	int   size_l;
	int   end;
	t_point size;
	int 		**map;
}	  		t_e;

typedef struct s_wtf
{
		int wtf;
		int wtf2;
		int wtf3;
		int go;
}				t_wtf;

typedef struct s_line
{
	int 		x1;
	int 		x2;
	int 		y1;
	int 		y2;
	int 		dx;
	int 		dy;
}				t_line;

typedef struct s_color
{
	int 	r;
	int 	g;
	int 	b;
	int 	a;
}				t_color;

int 		ft_keyboard(int keycode, t_e *e);
void	ft_line(int *image, int color, t_point pt1, t_point pt2);
unsigned int 		ft_color(int keycode, int R, int G, int B);
void 		ft_while(t_line *line, t_wtf *wtf, int *image, int color);
int			**ft_read(const char *file, int fd, t_e *e);
t_point ft_len_file(const char *str);
int			ft_splitlen(char **tab);
void    ft_trace(int **old, t_e *img, t_point size);

#endif
