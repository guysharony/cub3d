/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/20 10:41:30 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int		get_drawc(t_env *e, t_draw draw, int y)
{
	if (y < draw.drw.x)
		return (ft_color(e->ceiling[0], e->ceiling[1], e->ceiling[2]));
	else if (y >= draw.drw.y)
		return (ft_color(e->floor[0], e->floor[1], e->floor[2]));
	else
		return (get_wallc(e, draw, y));
}

void	mkimage(t_env *e, t_draw draw)
{
	int			x;
	int			y;
	int			buf[e->resolution[0]][e->resolution[1]];
	double		ZBuffer[e->resolution[0]];

	x = 0;
	while (x < e->resolution[0])
	{
		y = 0;
		draw = set_draw(e, x);
		while (y++ < e->resolution[1])
			buf[x][y] = get_drawc(e, draw, y);
		ZBuffer[x] = draw.wll;
		x++;
	}
	x = 0;
	while (x < e->game->sprite->size)
	{
		double spriteX = (e->game->sprite->sprite[x].x - e->player.pos.x) + 0.5;
		double spriteY = (e->game->sprite->sprite[x].y - e->player.pos.y) + 0.5;

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
					int color = ((int *)e->textureD[4])[texturew * texY + texX];
					if ((color & 0x00FFFFFF) != 0)
						buf[stripe][y] = color;
				}
			}
		}
		x++;
	}
	x = 0;
	while (x < e->resolution[0])
	{
		drawlinebuffer(e, x, 0, x, e->resolution[1] - 1, buf[x]);
		x++;
	}
}

void	draw(t_env *e)
{
	int			x;
	int			y;
	t_draw		draw;

	createenv(e);
	free(e->img_temp);
	createcontext(e);
	contexttoenv(e);
	mkimage(e, draw);
}
