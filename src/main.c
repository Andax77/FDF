/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:20:30 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/20 12:41:58 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, const char *argv[])
{
	printf("%d%s",argc, argv[1]);
	t_e		e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
  e.img_str = (int*)mlx_get_data_addr(e.img, &e.bpp, &e.size_l, &e.end);
	mlx_key_hook(e.win, ft_keyboard, &e);
	mlx_loop(e.mlx);
	return (0);
}
