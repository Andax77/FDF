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

typedef struct s_e
{
	void	*win;
	void	*mlx;
	void	*img;
	int   *img_string;
	int   bpp;
	int   size_l;
	int   end;
}	  		t_e;

typedef struct s_point
{
	double 	x;
	double 	y;
}				t_point;

typedef struct s_color
{
	int 	r;
	int 	g;
	int 	b;
	int 	a;
}				t_color;

int ft_keyboard(int keycode, t_e *e);
void  fill_image(int *image, int color);

#endif
