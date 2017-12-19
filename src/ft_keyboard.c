/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:23:46 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/18 18:22:35 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_keyboard(int keycode, t_e *e)
{
	int color;

	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 15)//RED
		color = 0xFF0000;
	if (keycode == 5)//GREEN
		color = 0x00FF00;
	if (keycode == 11)//BLUE
		color = 0x0000FF;
/*	if (keycode == 126)//UP
	if (keycode == 123)//LEFT
	if (keycode == 125)//DOWN
	if (keycode == 124)//RIGHT
	*/fill_image(e->image_string, color);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
	return (0);
}
