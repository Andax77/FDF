/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 12:07:59 by anhuang           #+#    #+#             */
/*   Updated: 2017/12/18 18:26:10 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 100
# define WIN_WIDTH 100

#include "../libft/libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_e
{
	void	*win;
	void	*mlx;
}				t_e;

int ft_keyboard(int keycode, t_e *e);

#endif
