/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:32:05 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 13:00:18 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	drawlinebuffer(t_env *e, int x1, int y1, int x2, int y2, int bff[])
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		dx1;
	int		dy1;
	int		px;
	int		py;
	int		xe;
	int		ye;
	int		i;

	i = 0;
	dx = x2 - x1;
	dy = y2 - y1;

	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;

	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
		while (x++ < xe)
		{
			if (px < 0)
				px = px + 2 *dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					y++;
				else
					y--;
				px = px + 2 * (dy1 - dx1);
			}
			(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
		while (y++ < ye)
		{
			if (py <= 0)
				py = py + 2 *dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					x++;
				else
					x--;
				py = py + 2 * (dx1 - dy1);
			}
			(e->img_temp)[x + y * e->resolution[0]] = bff[i++];
		}
	}
}

void	drawline(t_env *e, int x1, int y1, int x2, int y2, int color)
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		dx1;
	int		dy1;
	int		px;
	int		py;
	int		xe;
	int		ye;
	int		i;

	dx = x2 - x1;
	dy = y2 - y1;

	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;

	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		(e->img_temp)[x + y * e->resolution[0]] = color;
		while (x++ < xe)
		{
			if (px < 0)
				px = px + 2 *dy1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					y++;
				else
					y--;
				px = px + 2 * (dy1 - dx1);
			}
			(e->img_temp)[x + y * e->resolution[0]] = color;
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		(e->img_temp)[x + y * e->resolution[0]] = color;
		while (y++ < ye)
		{
			if (py <= 0)
				py = py + 2 *dx1;
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
					x++;
				else
					x--;
				py = py + 2 * (dx1 - dy1);
			}
			(e->img_temp)[x + y * e->resolution[0]] = color;
		}
	}
}
