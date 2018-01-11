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
	if (R > 0 && G < 255 && B == 0)
	{
		R -= 15;
		G += 15;
	}
	if (G > 0 && B < 255 && R == 0)
	{
		G -= 15;
		B += 15;
	}
	if (B > 0 && R < 255 && G == 0)
	{
		B -= 15;
		R += 15;
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

unsigned int 	ft_color(int keycode, int R, int G, int B)
{
	if (keycode == 24)//+
		return (ft_keycode(R, G, B));
	if (keycode == 27)//-
	{
		if (R < 255 && G > 0 && B == 0)
		{
			R += 15;
			G -= 15;
		}
		if (G < 255 && B > 0 && R == 0)
		{
			G += 15;
			B -= 15;
		}
		if (B < 255 && R > 0 && G == 0)
		{
			B += 15;
			R -= 15;
		}
	}
	return (R * pow(16, 4) + G * pow(16, 2) + B);
}

unsigned int 	ft_brightness(int keycode , int R, int G, int B)
{
	if (keycode == 33)//-
	{
		if (R > 0 && G > 0 && B > 0)
		{
			R -= 15;
			G -= 15;
			B -= 15;
		}
	}
	else
		if (R < 255 && G < 255 && B < 255)
		{
			R += 15;
			G += 15;
			B += 15;
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
	if (keycode == 33 || keycode == 30)
		e->clr = ft_brightness(keycode , e->clr / 65536, e->clr % 65536 / 256, e->clr % 65536 % 256);
	if (keycode == 27 || keycode == 24)
		e->clr = ft_color(keycode, e->clr / 65536, e->clr % 65536 / 256, e->clr % 65536 % 256);
	if (keycode == 15)
		e->clr = 0xFF0000;
	if (keycode == 5)
		e->clr = 0x00FF00;
	if (keycode == 11)
		e->clr = 0x0000FF;
	if (keycode == 126)//UP
		e->offset.y += 100;
	if (keycode == 124)//LEFT
		e->offset.x -= 100;
	if (keycode == 125)//DOWN
		e->offset.y -= 100;
	if (keycode == 123)//RIGHT
		e->offset.x += 100;
	if (keycode == 78)//-
		e->zoom /= 2;
	if (keycode == 69)//+
		e->zoom *= 2;
	if (keycode == 41)//-
		e->z += 2;
	if (keycode == 39)//+
		e->z -= 2;
	ft_trace(e->map, e, e->size);
	return (0);
}
