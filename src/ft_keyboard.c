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
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)//UP
	{
	}
	if (keycode == 123)//LEFT
	{
	}
	if (keycode == 125)//DOWN
	{
	}
	if (keycode == 124)//RIGHT
	{
	}
	mlx_pixel_put(e->mlx, e->win, 300, 300, 0xFF00FF);
	return (0);
}
