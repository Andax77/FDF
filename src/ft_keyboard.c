/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:23:46 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/04 18:46:01 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_keycode(int R, int G, int B)
{
	if (R != 0 && G != 255 && B == 0)
	{
		R -= 15;
		G += 15;
	}
	if (G != 0 && B != 255 && R == 0)
	{
		G -= 15;
		B += 15;
	}
	if (B != 0 && R != 255 && G == 0)
	{
		B -= 15;
		R += 15;
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

int 	ft_color(int keycode, int R, int G, int B)
{
	if (R == 0 && G == 0 && B == 0)
		R = 255;
	if (keycode == 24)//+
		return (ft_keycode(R, G, B));
	if (keycode == 27)//-
	{
		if (R != 255 && G != 0 && B == 0)
		{
			R += 15;
			G -= 15;
		}
		if (G != 255 && B != 0 && R == 0)
		{
			G += 15;
			B -= 15;
		}
		if (B != 255 && R != 0 && G == 0)
		{
			B += 15;
			R -= 15;
		}
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

int		ft_keyboard(int keycode, t_e *e)
{
	static int color;

	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 27 || keycode == 24)
		color = ft_color(keycode, color / 65536, color % 65536 / 256, color % 65536 % 256);
	if (keycode == 15)
		color = 0xFF0000;
	if (keycode == 5)
		color = 0x00FF00;
	if (keycode == 11)
		color = 0x0000FF;
	printf("COULEUR : %d\n", color);
/*	if (keycode == 126)//UP
	if (keycode == 123)//LEFT
	if (keycode == 125)//DOWN
	if (keycode == 124)//RIGHT
	*/
	ft_line(e->img_str, color);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
