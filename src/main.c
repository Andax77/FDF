/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:20:30 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/18 18:21:17 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, const char *argv[])
{
	printf("%d%s",argc, argv[1]);
	int		x;
	int		y;
	t_e		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 400, 400,"mlx 42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, 0x00FFFFFF);
			x ++;
		}
		y++;
	}
	mlx_key_hook(e.win, ft_keyboard, &e);
	mlx_loop(e.mlx);
	return 0;
}
