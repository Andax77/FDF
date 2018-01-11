/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:08:48 by anhuang           #+#    #+#             */
/*   Updated: 2018/01/04 15:14:40 by anhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	wide_line(t_point pos, t_point delta, t_point inc, t_e *e)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * (delta.y - delta.x);
	while (i <= delta.x)
	{
		if (pos.y < WIN_HEIGHT && pos.x >= 0 && pos.x < WIN_WIDTH && pos.y >= 0)
			e->img_str[pos.y * WIN_WIDTH + pos.x] = e->clr;
		if (p >= 0)
		{
			pos.y += inc.y;
			p += 2 * (delta.y - delta.x);
		}
		else
			p += 2 * delta.y;
		pos.x += inc.x;
		++i;
	}
}

static void	tall_line(t_point pos, t_point delta, t_point inc, t_e *e)
{
	int	p;
	int	i;

	i = 0;
	p = 2 * (delta.x - delta.y);
	while (i < delta.y)
	{
		if (pos.y < WIN_HEIGHT && pos.x >= 0 && pos.x < WIN_WIDTH && pos.y >= 0)
			e->img_str[pos.y * WIN_WIDTH + pos.x] = e->clr;
		if (p >= 0)
		{
			pos.x += inc.x;
			p += 2 * (delta.x - delta.y);
		}
		else
			p += 2 * delta.x;
		pos.y += inc.y;
		++i;
	}
}

void		ft_line(t_point start, t_point end, t_e *e)
{
	t_point	delta;
	t_point	inc;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	inc.x = (delta.x > 0) ? 1 : -1;
	inc.y = (delta.y > 0) ? 1 : -1;
	delta.x = abs(delta.x);
	delta.y = abs(delta.y);
	if (delta.x > delta.y)
		wide_line(start, delta, inc, e);
	else
		tall_line(start, delta, inc, e);
}
