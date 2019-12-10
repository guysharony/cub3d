/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:01:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/10 08:34:18 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_coo	ray_dir(t_env *e, double cameraX)
{
	t_coo	ray;

	ray.x = e->player.dir.x + e->plane.x * cameraX;
	ray.y = e->player.dir.y + e->plane.y * cameraX;
	return (ray);
}

t_coo	dlt_dst(t_env *e, t_coo ray)
{
	t_coo	dlt;

	dlt.x = abs(1 / ray.x);
	dlt.y = abs(1 / ray.y);
	return (dlt);
}

t_pos	map_pos(t_env *e)
{
	t_pos	map;

	map.x = (int)e->player.pos.x;
	map.y = (int)e->player.pos.y;
	return (map);
}

t_pos	stp_int(t_coo ray)
{
	t_pos	stp;

	if (ray.x < 0)
		stp.x = -1;
	else
		stp.x = 1;
	if (ray.y < 0)
		stp.y = -1;
	else
		stp.y = 1;
	return (stp);
}

t_coo	sld_int(t_env *e, t_pos map, t_coo dlt, t_coo ray)
{
	t_coo	sld;

	if (ray.x < 0)
		sld.x = (e->player.pos.x - map.x) * dlt.x;
	else
		sld.x = (map.x + 1.0 - e->player.pos.x) * dlt.x;
	if (ray.x < 0)
		sld.y = (e->player.pos.y - map.y) * dlt.y;
	else
		sld.y = (map.y + 1.0 - e->player.pos.y) * dlt.y;
	return (sld);
}

void	draw(t_env *e)
{
	int			x;
	int			hit;
	int			sde;
	int			lnh;
	int			clr;
	int			buf[H];
	char		mapc;
	double		cam;
	double		wll;
	t_coo		ray;
	t_coo		sld;
	t_coo		dlt;
	t_pos		drw;
	t_pos		map;
	t_pos		stp;

	x = 0;
	CreateEnv(e);
	CreateContext(e);
	ContextToEnv(e);
	while (x < W)
	{
		cam = 2 * x / (double)(W) - 1;
		ray = ray_dir(e, cam);
		map = map_pos(e);
		dlt = dlt_dst(e, ray);
		hit = 0;
		if (ray.x < 0)
		{
			stp.x = -1;
			sld.x = (e->player.pos.x - map.x) * dlt.x;
		}
		else
		{
			stp.x = 1;
			sld.x = (map.x + 1.0 - e->player.pos.x) * dlt.x;
		}
		if (ray.y < 0)
		{
			stp.y = -1;
			sld.y = (e->player.pos.y - map.y) * dlt.y;
		}
		else
		{
			stp.y = 1;
			sld.y = (map.y + 1.0 - e->player.pos.y) * dlt.y;
		}
		while (hit == 0)
		{
			if (sld.x < sld.y)
			{
				sld.x += dlt.x;
				map.x += stp.x;
				sde = 0;
			}
			else
			{
				sld.y += dlt.y;
				map.y += stp.y;
				sde = 1;
			}
			mapc = e->game->map[map.x][map.y];
			if (mapc > '0' && mapc != 'N' && mapc != 'S' && mapc != 'E' && mapc !='W')
				hit = 1;
		}
		if (sde == 0)
			wll = (map.x - e->player.pos.x + (1 - stp.x) / 2) / ray.x;
		else
			wll = (map.y - e->player.pos.y + (1 - stp.y) / 2) / ray.y;

		lnh = (int)(H / wll);
		drw.x = -lnh / 2 + H / 2;
		if (drw.x < 0)
			drw.x = 0;
		drw.y = lnh / 2 + H / 2;
		if (drw.y >= H)
			drw.y = H - 1;

		int texNum = e->game->map[map.x][map.y] - 1 - 48;
		double wallX;
		if (sde == 0) 
			wallX = e->player.pos.y + wll * ray.y;
		else
			wallX = e->player.pos.x + wll * ray.x;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)(texWidth));
		if(sde == 0 && ray.x > 0)
			texX = texWidth - texX - 1;
		if(sde == 1 && ray.y < 0)
			texX = texWidth - texX - 1;
		for(int y = drw.x; y < drw.y; y++)
		{
			int d = y * 256 - H * 128 + lnh * 128;
			int texY = ((d * texHeight) / lnh) / 256;
			if (sde == 0)
			{
				if (ray.x > 0)
					clr = ((int *)e->textureD[0])[((int *)e->texture[0])[0] * texX + texY];
				else
					clr = ((int *)e->textureD[1])[((int *)e->texture[1])[0] * texX + texY];
			}
			else if (sde == 1)
			{
				if (ray.y > 0)
					clr = ((int *)e->textureD[2])[((int *)e->texture[2])[0] * texX + texY];
				else
					clr = ((int *)e->textureD[3])[((int *)e->texture[3])[0] * texX + texY];
			}
			if (sde == 1)
				clr = (clr >> 1) & 8355711;
			buf[y - drw.x] = clr;
		}
		DrawLineBuffer(e, x, drw.x, x, drw.y, buf);
		x++;
	}
}
