/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:26:23 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/12 12:36:15 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int	ft_keycode(int r, int g, int b)
{
	if (r > 0 && g < 255 && b == 0)
	{
		r -= 15;
		g += 15;
	}
	if (g > 0 && b < 255 && r == 0)
	{
		g -= 15;
		b += 15;
	}
	if (b > 0 && r < 255 && g == 0)
	{
		b -= 15;
		r += 15;
	}
	return (r * pow(16, 4) + g * pow(16, 2) + b);
}

unsigned int	ft_color(int keycode, int r, int g, int b)
{
	if (keycode == 24)
		return (ft_keycode(r, g, b));
	if (keycode == 27)
	{
		if (r < 255 && g > 0 && b == 0)
		{
			r += 15;
			g -= 15;
		}
		if (g < 255 && b > 0 && r == 0)
		{
			g += 15;
			b -= 15;
		}
		if (b < 255 && r > 0 && g == 0)
		{
			b += 15;
			r -= 15;
		}
	}
	return (r * pow(16, 4) + g * pow(16, 2) + b);
}

unsigned int	ft_brightness(int keycode, int r, int g, int b)
{
	if (keycode == 33)
	{
		if (r > 0 && g > 0 && b > 0)
		{
			r -= 15;
			g -= 15;
			b -= 15;
		}
	}
	else
	{
		if (r < 255 && g < 255 && b < 255)
		{
			r += 15;
			g += 15;
			b += 15;
		}
	}
	return (r * pow(16, 4) + g * pow(16, 2) + b);
}

void			ft_keyboard2(int keycode, t_e *e)
{
	if (keycode == 15)
		e->clr = 0xFF0000;
	if (keycode == 5)
		e->clr = 0x00FF00;
	if (keycode == 11)
		e->clr = 0x0000FF;
	if (keycode == 126)
		e->offset.y += 100;
	if (keycode == 124)
		e->offset.x -= 100;
	if (keycode == 125)
		e->offset.y -= 100;
	if (keycode == 123)
		e->offset.x += 100;
	if (keycode == 78)
	{
		e->zoom /= 2;
		e->z /= 2;
	}
	if (keycode == 69)
	{
		e->zoom *= 2;
		e->z *= 2;
	}
}

int				ft_keyboard(int keycode, t_e *e)
{
	if (keycode == 53)
	{
		while (e->size.y-- > 0)
			free(e->map[e->size.y]);
		free(e->map);
		mlx_destroy_window(e->mlx, e->win);
		ft_error("FDF has been destroyed.\n");
	}
	if (keycode == 33 || keycode == 30)
		e->clr = ft_brightness(keycode, e->clr / 65536, e->clr % 65536 / 256,
				e->clr % 65536 % 256);
	if (keycode == 27 || keycode == 24)
		e->clr = ft_color(keycode, e->clr / 65536, e->clr % 65536 / 256,
				e->clr % 65536 % 256);
	ft_keyboard2(keycode, e);
	if (keycode == 41)
		e->z += 2;
	if (keycode == 39)
		e->z -= 2;
	ft_trace(e->map, e, e->size);
	return (0);
}
