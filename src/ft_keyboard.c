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

unsigned int	ft_keycode(int R, int G, int B)
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
	if (R != 255 && G != 255 && B != 255 && R != 0 && G != 0 && B != 0)
	{
		R += 15;
		G += 15;
		B += 15;
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

unsigned int 	ft_color(int keycode, int R, int G, int B)
{
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
		if (R != 0 && G != 0 && B != 0)
		{
			R -= 15;
			G -= 15;
			B -= 15;
		}
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

int		ft_keyboard(int keycode, t_e *e)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 27 || keycode == 24)
		e->color = ft_color(keycode, e->color / 65536, e->color % 65536 / 256, e->color % 65536 % 256);
	if (keycode == 15)
		e->color = 0xFF0000;
	if (keycode == 5)
		e->color = 0x00FF00;
	if (keycode == 11)
		e->color = 0x0000FF;
	if (keycode == 126)//UP
		e->offset.y += 100;
	if (keycode == 123)//LEFT
		e->offset.x -= e->size.x * e->size.y;
	if (keycode == 125)//DOWN
		e->offset.y -= 100;
	if (keycode == 124)//RIGHT
		e->offset.x += e->size.x * e->size.y;
	ft_trace(e->map, e, e->size);
	return (0);
}
