/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:32:05 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/26 11:49:50 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	DrawTriangle(t_env *e, int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
	DrawLine(e, x1, y1, x2, y2, color);
	DrawLine(e, x2, y2, x3, y3, color);
	DrawLine(e, x3, y3, x1, y1, color);
}

void	DrawLineBuffer(t_env *e, int x1, int y1, int x2, int y2, int bff[])
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
		(e->img_temp)[x + y * W] = bff[i++];
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
			(e->img_temp)[x + y * W] = bff[i++];
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
		(e->img_temp)[x + y * W] = bff[i++];
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
			(e->img_temp)[x + y * W] = bff[i++];
		}
	}
}

void	DrawLine(t_env *e, int x1, int y1, int x2, int y2, int color)
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
		(e->img_temp)[x + y * W] = color;
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
			(e->img_temp)[x + y * W] = color;
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
		(e->img_temp)[x + y * W] = color;
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
			(e->img_temp)[x + y * W] = color;
		}
	}
}
