/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/19 14:28:36 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	draw(t_env *e)
{
	int			x;
	int			y;
	int			buf[e->resolution[0]][e->resolution[1]];
	double		ZBuffer[e->resolution[0]];
	t_draw		draw;

	x = 0;
	createenv(e);
	free(e->img_temp);
	createcontext(e);
	contexttoenv(e);
	while (x < e->resolution[0])
	{
		draw = set_draw(e, x);
		for (y = 0; y < e->resolution[1]; y++)
		{
			if (y < (e->resolution[1] / 2))
				buf[x][y] = ft_color(e->ceiling[0], e->ceiling[1], e->ceiling[2]);
			else
				buf[x][y] = ft_color(e->floor[0], e->floor[1], e->floor[2]);
		}
		for (y = draw.drw.x; y < draw.drw.y; y++)
		{
			draw.clr = get_wallc(e, draw, y);
			buf[x][y] = draw.clr;
		}
		ZBuffer[x] = draw.wll;
		x++;
	}
	double spriteX = 4.0 - e->player.pos.x;
	double spriteY = 4.0 - e->player.pos.y;

	double invDet = 1.0 / (e->plane.x * e->player.dir.y - e->player.dir.x * e->plane.y);
	double transformX = invDet * (e->player.dir.y * spriteX - e->player.dir.x * spriteY);
	double transformY = invDet * (-e->plane.y * spriteX + e->plane.x * spriteY);
	int spriteScreenX = (int)((e->resolution[0] / 2) * (1 + transformX / transformY));

	int spriteHeight = abs((int)(e->resolution[1] / (transformY)));
	int drawStartY = -spriteHeight / 2 + e->resolution[1] / 2;
	if (drawStartY < 0)
		drawStartY = 0;
	int drawEndY = spriteHeight / 2 + e->resolution[1] / 2;
	if (drawEndY >= e->resolution[1])
		drawEndY = e->resolution[1] - 1;

	int spriteWidth = abs((int)(e->resolution[1] / (transformY)));
	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if (drawStartX < 0)
		drawStartX = 0;
	int drawEndX = spriteWidth / 2 + spriteScreenX;
	if (drawEndX >= e->resolution[0])
		drawEndX = e->resolution[0] - 1;

	for (int stripe = drawStartX; stripe < drawEndX; stripe++)
	{
		int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texturew / spriteWidth) / 256;
		if (transformY > 0 && stripe > 0 && stripe < e->resolution[0] && transformY < ZBuffer[stripe])
		{
			for (int y = drawStartY; y < drawEndY; y++)
			{
				int d = (y) * 256 - e->resolution[1] * 128 + spriteHeight * 128;
				int texY = ((d * textureh) / spriteHeight) / 256;
				int color = 750;
				buf[stripe][y] = color;
			}
		}
	}
	x = 0;
	while (x < e->resolution[0])
	{
		drawlinebuffer(e, x, 0, x, e->resolution[1] - 1, buf[x]);
		x++;
	}
}
